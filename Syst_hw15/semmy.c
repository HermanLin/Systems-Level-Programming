#include "header.h"

int main(int argc, char *argv[]) {

  int sem, shm, sc, fd;
  char *buffer;// = malloc(1024);
    
  if (!strcmp(argv[1], "-c")) {
    sem = semget(SEMKEY, 1, IPC_CREAT | IPC_EXCL | 0666);
    if (sem == -1) {
      printf("semaphore already exists\n");
      return 0;
    } else {
      printf("sepmaphore created: %d\n", sem);
      union semun su;
      su.val = 1;
      sc = semctl(sem, 0, SETVAL, su);
      printf("value set: %d\n", sc);
			
      //shared memory
      shm = shmget(SHMKEY, sizeof(int), IPC_CREAT | 0666);
      printf("shared memory created\n");			
			
      fd = open("story.txt", O_CREAT | O_TRUNC);
      close(fd);
      printf("story file created\n");
    }
  } else if (!strcmp(argv[1], "-v")) {
    
    fd = open("story.txt", O_RDONLY);

    struct stat st;
    stat("story.txt", &st);

    buffer = calloc(st.st_size,sizeof(char));
    
    read(fd, buffer, st.st_size);
    printf("Story so far:\n%s\n", buffer);
		
  } else if (!strcmp(argv[1], "-r")) {

    printf("Waiting for access to the Semaphone...\n");
    int semid;
    semid = semget(SEMKEY, 1, 0);
    if (semid == -1) {
      printf("Create a new story using ./control -c\n");
      exit(1);
    }
    
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;
    semop(semid, &sb, 1);
    printf("Access to Semaphone approved...\n");
    
    sem = semget(SEMKEY, 1, 0666);
    printf("semaphore removed:%d\n", semctl(sem, 1, IPC_RMID));
		
    shm = shmget(SHMKEY, sizeof(int), 0);
    shmctl(shm, IPC_RMID, 0);
    printf("shared memory removed\n");
		
    fd = open("story.txt", O_RDONLY);

    struct stat st;
    stat("story.txt", &st);

    buffer = calloc(st.st_size,sizeof(char));
    
    read(fd, buffer, st.st_size);
    printf("Story:\n%s\n", buffer);
    close(fd);
    
    remove("story.txt");
  }
  return 0;
}
