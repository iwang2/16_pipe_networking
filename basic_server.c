#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );
  printf("wkp: %d\n", from_client);
  printf("cts: %d\n", to_client);

  char input[2000];
  int i;
  while(1){
    memset(&output, 0, sizeof(output));
    read(from_client, input, sizeof(input));
    printf("received input: %s\n", input);

    for(i = 0; input[i]; i++){
      if(i % 2 == 0){
	input[i] = toupper(input[i]);
      } else {
	input[i] = tolower(input[i]);
      }
    }
    
    printf("modified: %s\n", input);
    write(to_client, input, strlen(input));
  }
}
