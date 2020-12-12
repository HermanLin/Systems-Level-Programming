#include "header.h"

int main() {
	
	int semid, shmid, fd;
	
	semid = semget(SEMKEY, 1, 0);
	if (semid == -1) {
		printf("Create a new story using ./control -c\n");
		exit(1);
	}
	
	printf("Waiting for access to the Semaphone...\n");
	struct sembuf sb;
	sb.sem_num = 0;
	sb.sem_op = -1;
	sb.sem_flg = SEM_UNDO;
	semop(semid, &sb, 1);
	printf("Access to Semaphone approved...\n");
	
	fd = open("story.txt", O_APPEND | O_RDWR);
	printf("story.txt opened\n");
	shmid = shmget(SHMKEY, sizeof(int), 0);
	int *size = shmat(shmid, 0, 0);
	char *last_line = (char *)calloc(1, *size + 1);
	lseek(fd, -1 * *size, SEEK_END);
	read(fd, last_line, *size);
	printf("Most recent addition to the Semaphone:\n\n %s\n", last_line);
	
	char new_line[1024];
	printf("Add a new line to the Semaphone:\n");
	fgets(new_line, sizeof(new_line), stdin);
	lseek(fd, 0, SEEK_END);
	write(fd, new_line, strlen(new_line));
	*size = strlen(new_line);
	
	shmdt(size);
	sb.sem_op = 1;
	semop(semid, &sb, 1);
	free(last_line);
	
	return 0;
}
