#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main() {

  int f;
  int fds1[2];
	int fds2[2];
  pipe(fds1);
	pipe(fds2);
	
  f = fork();

  if (!f) {
    close(fds1[1]);
    close(fds2[0]);
    int math;
    read(fds1[0], &math, sizeof(math));
    math += 5;
		printf("[child] mathus completus: %d\n", math);
		write(fds2[1], &math, sizeof(math));
  } else {
		int do_magic = 10;
    close(fds1[0]);
    close(fds2[1]);
		printf("[parent] challenging child: %d\n", do_magic);
    write(fds1[1], &do_magic, sizeof(do_magic));
		read(fds2[0], &do_magic, sizeof(do_magic));
		printf("[parent] stupefied: %d\n", do_magic);
  }

  return 0;
}
