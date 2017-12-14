#include "pipe_networking.h"

int main() {
  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );
  printf("wkp: %d\n", to_server);
  printf("cts: %d\n", from_server);
  
  while(1){
    printf("Type a message to the server:\n");
    
    char input [sizeof(char) * 2000];    
    fgets(input, sizeof(input), stdin);
    printf("Original Input: %s\n", input);
    write(to_server, input, strlen(input));
    
    char output [strlen(input)];
    read(from_server, output, strlen(input));
    printf("Modified Output: %s\n", output);
  }
}
