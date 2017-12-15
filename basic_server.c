#include "pipe_networking.h"

int main() {
  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  char buff[BUFFER_SIZE];
  int i;
  while(1){
    if(read(from_client, buff, sizeof(buff)) == 0){
      exit(0);
    }
    printf("received input: %s\n", buff);

    for(i = 0; buff[i]; i++){
      if(i % 2 == 0){
	buff[i] = toupper(buff[i]);
      } else {
	buff[i] = tolower(buff[i]);
      }
    }
    
    printf("modified: %s\n", buff);
    write(to_client, buff, sizeof(buff));
  }
}
