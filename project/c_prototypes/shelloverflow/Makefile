all: login_linux

login_linux: login_linux.c pwent.h pwent.c
	gcc -g -Wall pwent.c login_linux.c -lcrypt -o login_linux -lm

build: login_linux

clean:
	rm -f *.o mylogin login_linux
