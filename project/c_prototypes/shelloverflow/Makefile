all: login_linux

login_linux: login_linux.c
	gcc -g -w login_linux.c -o login_linux -lm

build: login_linux

clean:
	rm -f *.o login_linux
