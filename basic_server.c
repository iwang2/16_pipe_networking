#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  char input[sizeof(char) * 100];
  from_client = server_handshake( &to_client );

  while(1){
    read(from_client, input, sizeof(input));
    char * ouptut =  strcpy(input);
    strcat(output, "cat");
    write(*to_client, output, sizeof(output));

  }
}
