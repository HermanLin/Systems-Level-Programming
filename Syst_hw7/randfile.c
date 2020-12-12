#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int grand() {

  //decl
  int *r;
  int rand;
  int fd;

  //init
  fd = open("/dev/random", O_RDONLY);
  r = malloc(sizeof(int));

  //read
  read(fd,r,sizeof(r));
  rand = *r;

  //return
  free(r);
  close(fd);
  return rand;
}



int main() {

  //decl
  int i;
  int fd;
  int drand[10];
  int rrand[10];

  //generate
  printf("Generating random numbers:\n");
  for(i = 0; i < 10; i++) {
    drand[i] = grand();
    printf("\t random %d: %d\n",i,drand[i]);
  }
  
  //write
  fd = open("randout", O_CREAT | O_WRONLY, 0600);
  printf("\nWriting numbers to file...\n");
  write(fd, drand, sizeof(drand));
  close(fd);

  //read
  fd = open("randout", O_RDONLY, 0600);
  printf("\nReading numbers from file...\n");
  read(fd, rrand, sizeof(rrand));
  close(fd);
  
  //print
  printf("\nVerification that written values were the same:\n");
  for(i = 0; i < 10; i++) {
    printf("\t random %d: %d\n",i,rrand[i]);
  }

  return 0;
}
