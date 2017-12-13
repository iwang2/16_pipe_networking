#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  char * data = malloc(sizeof(char) * 100);
  char * output = malloc(sizeof(;
  while(1){
    fgets(data, sizeof(data), stdin);
    printf("Original Input: %s\n", data);
    to_server = client_handshake( &to_server );
    
    write(to_server, data, sizeof(data));
    read(from_server, output, sizeof(output));
    printf("Modified Output: %s\n", output);
  }
}
