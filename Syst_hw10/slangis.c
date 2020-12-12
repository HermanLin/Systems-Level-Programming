#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void sighandler (int signo) {
	
	if (signo == SIGINT) {
		printf("Exiting prgm due to: SIGINT (2)...");
		exit(1);
	}
	if (signo == SIGUSR1) {
		printf("Parent Process ID: %d\n", getppid());
	}
}

int main() {
	
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);
	
	while(1) {
		printf("Process ID: %d\n", getpid());
		sleep(1);
	}
	
	return 0;
}