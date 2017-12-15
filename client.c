#include "pipe_networking.h"

int main() {
  int to_server;
  int from_server;

  char buff[BUFFER_SIZE];

  from_server = client_handshake( &to_server );
  
  while(1){
    printf("\nType a message to the server:");
    
    fgets(buff, sizeof(buff), stdin);
    *strchr(buff, '\n') = 0;
    printf("Original Input: %s\n", buff);
    write(to_server, buff, sizeof(buff));
    
    read(from_server, buff, sizeof(buff));
    printf("Modified Output: %s\n", buff);
  }
}
