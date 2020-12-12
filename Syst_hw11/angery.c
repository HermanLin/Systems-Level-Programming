#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

char ** parse_args (char *line) {
  
  char **args = (char**)calloc((int)strlen(line) / 2 + 1, sizeof(char*));
  char *s1 = line;
  int i = 0;

  while (s1) {
    args[i++] = strsep(&s1, " ");
  }
  
  return args;
}

int main() {
  
  //decl
  char line[100];
  char **argv;
  const time_t timer = time(NULL);

  //test
  sprintf(line,"echo %s", ctime(&timer));
  argv =  parse_args(line);
  execvp(argv[0], argv);

  return 0;
}
