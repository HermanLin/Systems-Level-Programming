#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;
  char buffer[BUFFER_SIZE];

  from_server = client_handshake( &to_server );

  while (1) {
    printf("enter data: ");
    //printf("writing");
    fgets(buffer, sizeof(buffer), stdin);
    //printf("writing");
    *strchr(buffer, '\n') = 0;
    //printf("writing");
    write(to_server, buffer, sizeof(buffer));
    //printf("wrote");
    read(from_server, buffer, sizeof(buffer));
    printf("received: [%s]\n", buffer);
  }
}
