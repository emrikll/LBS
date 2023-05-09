/* $Header: https://svn.ita.chalmers.se/repos/security/edu/course/computer_security/trunk/lab/login_linux/login_linux.c 585 2013-01-19 10:31:04Z pk@CHALMERS.SE $ */

/* gcc -std=gnu99 -Wall -g -o mylogin login_linux.c -lcrypt */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>

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
	char important1[LENGTH] = "**IMPORTANT 1**";

	char salts[] =
			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";

	char user[LENGTH];

	char important2[LENGTH] = "**IMPORTANT 2**";

	printf("Starting..\n");

	//char   *c_pass; //you might want to use this variable later...
	char prompt[] = "password: ";
	char user_pass[LENGTH];
	
	printf("user: ");
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

	if(user == NULL) {
		exit(0);
	}

	printf("password: ");
	fflush(NULL); /* Flush all  output buffers */
	__fpurge(stdin); /* Purge any data in stdin buffer */

	//Use fgets instead of gets
	if(fgets(user_pass, LENGTH, stdin) == NULL){  
		exit(0); 
	}

	//To prevent buffer overflow, we replace the enter key with end string
	for(int i = 0 ; i < LENGTH ; i++){		
		if(user_pass[i] == '\n'){
			user_pass[i] = '\0';
		}
	}

	if(user_pass == NULL) {
		exit(0);
	}
	printf("Your password was %s\n", user_pass);
	
	return 0;
}
