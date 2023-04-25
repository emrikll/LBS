/* $Header: https://svn.ita.chalmers.se/repos/security/edu/course/computer_security/trunk/lab/login_linux/login_linux.c 585 2013-01-19 10:31:04Z pk@CHALMERS.SE $ */

/* gcc -std=gnu99 -Wall -g -o mylogin login_linux.c -lcrypt */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <signal.h>
#include <pwd.h>
#include <sys/types.h>
#include <crypt.h>
#include <time.h>
#include <math.h>
/* Uncomment next line in step 2 */
#include "pwent.h" */

#define TRUE 1
#define FALSE 0
#define LENGTH 16

void sighandler() {

	//TODO: uncomment wgen demoing!
	signal(SIGINT, SIG_IGN);/*ctrl c*/
	signal(SIGTSTP, SIG_IGN);/*ctrl z*/
	signal(SIGABRT, SIG_IGN);/*ctrl -/*/
}


int main(int argc, char *argv[]) {
	
	mypwent *passwddata;


	char important1[LENGTH] = "**IMPORTANT 1**";

	char salts[] =
			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";

	char user[LENGTH];

	char important2[LENGTH] = "**IMPORTANT 2**";

	printf("Starting..\n");

	//char   *c_pass; //you might want to use this variable later...
	char prompt[] = "password: ";
	char *user_pass;

	sighandler();

	while (TRUE) {
		/* check what important variable contains - do not remove, part of buffer overflow test */
		printf("Value of variable 'important1' before input of login name: %s\n",
				important1);
		printf("Value of variable 'important2' before input of login name: %s\n",
				important2);

		printf("login: ");
		fflush(NULL); /* Flush all  output buffers */
		__fpurge(stdin); /* Purge any data in stdin buffer */

		//Use fgets instead of gets
		if(fgets(user, LENGTH, stdin) == NULL){  
			exit(0); 
		}

		//To prevent buffer overflow, we replace the enter key with end string
		for(int i = 0 ; i < LENGTH ; i++){		
			if(user[i] == '\n'){
				user[i] = '\0';
			}
		}
			

		/* check to see if important variable is intact after input of login name - do not remove */
		printf("Value of variable 'important 1' after input of login name: %*.*s\n",
				LENGTH - 1, LENGTH - 1, important1);
		printf("Value of variable 'important 2' after input of login name: %*.*s\n",
		 		LENGTH - 1, LENGTH - 1, important2);

		user_pass = getpass(prompt);
		passwddata = mygetpwnam(user);


		if (passwddata != NULL) {
			/* You have to encrypt user_pass for this to work */
			/* Don't forget to include the salt */
			//crypt(user_pass, passwddata -> passwd_salt)

			//If the user is locked out, skip this iteration
			if(passwddata->locked > time(NULL)) {
				printf("This account is locked. Please try again later\n");
				continue;
			}

			passwddata->locked = 0;
			
			// compare the encrypted entered password + salt from db with the stored password in db 
			//strcmp returns 0 on equal passwords
			if (!strcmp(crypt(user_pass, passwddata -> passwd_salt) , passwddata->passwd)) {
				printf(" You're in !\n");
				passwddata->pwfailed = 0;	//reset failed logins
				passwddata->pwage++;

				//check age of password and prompt change on old password
				if (passwddata->pwage >= 10) {
					printf("You have now logged in with this password %d (>=10) times. You should consider changing it.\n", passwddata->pwage);
					printf("Would you like to change your password, please answer 'y' or 'n'? ");
					
					char answer[2];
				
					__fpurge(stdin); /* Purge any data in stdin buffer */

					//Read the answer from the user with secure fgets
					if(fgets(answer, 2, stdin) == NULL){  
						exit(0); 
					}

					for(int i = 0 ; i < 2 ; i++){		
						if(answer[i] == '\n'){
							answer[i] = '\0';
						}
					}
					
					//Check if the user wants to change password or not
					switch (answer[0]) {
						case 'y': 
							int my_pipe[2], nbytes;
							char    readbuffer[80];

							int d = pipe(my_pipe);
							if (d < 0) {
								printf("Something went wrong, will exit password creation: Pipe failed to create.");
								break;
							}

							//Randomize the salt
							srand(time(NULL));
							char salt1 = salts[rand() % 65];
							char salt2 = salts[rand() % 65];
							char salt[3] = {salt1, salt2};

							//We need to fork to have the child execute ./makepass
							//The parent will read the result in the pipe my_pipe
							int pid = fork();

							if (pid == 0 ){	
								//Child process
								char *args[]={"./makepass",salt, NULL};
        						dup2(my_pipe[1], 1); // redirect stdout
								close(my_pipe[0]); // Child doesn't need to read
								int e = execvp(args[0], args);
								if (e < 0) {
									printf("Failed to remake password.\n");
									exit(0);
								}
							} else if (pid > 0) {
								//Parent process
								waitpid(pid);
								printf("Changing password done\n");
								close(my_pipe[1]); // parent doesn't write
								nbytes = read(my_pipe[0], readbuffer, sizeof(readbuffer)); //read pipe and place in readbuffer
								if (nbytes < 0) {
									printf("Something went wrong, will exit password creation: Nothing in buffer from pipe.");
									break;
								}
								close(my_pipe[0]);
							}

							fflush(NULL); /* Flush all  output buffers */
							__fpurge(stdin); /* Purge any data in stdin buffer */

							passwddata->passwd = readbuffer;
							passwddata->passwd_salt = salt;
							passwddata->pwage = 0;

							break;
						default:
							printf("The password will not be changed.\n");
					}
				}

				//open command interpreter with logged in user 
				int n = mysetpwent(user, passwddata);
				if (n<0) {
					printf("Failed to update user in database. Exiting...\n");
					exit(-1);
				}
				n = setuid(passwddata->uid);

				if (n < 0) {
					printf("You are not allowed to sign into this user!\n");
				} else {
					char *args[]={"/bin/sh", NULL};
					int e = execvp(args[0], args);
					if (e < 0) {
						printf("Failed to create terminal. Exiting...\n");
						exit(-1);
					}
				}
			} else {
				//login was incorrect
				printf("Login Incorrect \n");
				passwddata->pwfailed++;	
				//check number of failed logins, and lock account for pow(2,passwddata->pwfailed-3)*60 minutes from current time  			
				if(passwddata->pwfailed > 2) {
					printf("You have failed too many times (%d). Your account will be locked for %d minutes.\n", passwddata->pwfailed, (int)pow(2,passwddata->pwfailed-3));
					passwddata -> locked = time(NULL) + (int)pow(2,passwddata->pwfailed-3)*60;
				}
			}
			//update password data for user 
			mysetpwent(user, passwddata);
		}
	}
	return 0;
}
