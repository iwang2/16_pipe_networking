#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  char * input = malloc(sizeof(char) * 500);
  char * output = malloc(sizeof(char) * 500);
  to_server = client_handshake( &to_server );

  while(1){
    fgets(input, sizeof(input), stdin);
    printf("Original Input: %s\n", input);
    write(to_server, input, sizeof(input));
    read(from_server, output, sizeof(output));
    printf("Modified Output: %s\n", output);
  }
}
