#include "pipe_networking.h"
#include <signal.h>

void process(char *s);
void subserver(int from_client);

static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("luigi");
    exit(0);
  }
}

int main() {
  signal(SIGINT, sighandler);
  int from_client, f;
  
  while(1){
    from_client = server_setup();    
    
    if (!fork()) { //child
      subserver(from_client);
    } else { //parent
      close(from_client);
    }
  }
}

void subserver(int from_client) {

  int to_client = server_connect(from_client);
  char buffer[BUFFER_SIZE];
  
  while(read(from_client, buffer, sizeof(buffer))) {
    process(buffer);
    write(to_client, buffer, sizeof(buffer));
  }
  exit(0);
}

void process(char *s) { //rot13
  int i;
  for (i = 0; '\0' != s[i]; i++) {
    char c = *(s + i);
    if (('a' <= c && 'n' > c) || ('A' <= c && 'N' > c)) {
      *(s + i) += 13;
    } else if (('n' <= c && 'z' >= c) || ('N' <= c && 'Z' >= c)) {
      *(s + i) -= 13;
    }
  }
  printf("[rot13] %s\n", s);
}
