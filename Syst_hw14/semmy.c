#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

#define KEY 4839

void print_args(int c, char *v[]) {
  int i;
  //printf("%d", c);
  for (i = 0; i < c; i++) {
    printf("%s ", v[i]);
  }
  printf("\n");
}


int main(int argc, char *argv[]) {

  int sem;

  //print_args(argc, argv);
	if (!strcmp(argv[1], "-c")) {
		sem = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0666);
		if (sem == -1) {
			printf("semaphore already exists\n");
			return 0;
		}
		semctl(sem, 0, SETVAL, atoi(argv[2]));
		printf("sepmaphore created: %d\n", sem);
		printf("value set: %d\n", semctl(sem, 0, GETVAL, 0));
	} else if (!strcmp(argv[1], "-v")) {
		sem = semget(KEY, 1, 0666);
		printf("semaphore value: %d\n", semctl(sem, 0, GETVAL, 0));
	} else if (!strcmp(argv[1], "-r")) {
		sem = semget(KEY, 1, 0666);
		printf("semaphore removed: %d\n", semctl(sem, 1, IPC_RMID));
	}
  return 0;
}
