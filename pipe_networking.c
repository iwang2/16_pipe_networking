#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Perofrms the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  mkfifo("stc", 0600);
  int fd = open("stc", O_RDONLY | O_CREAT | O_EXCL, 0600);
  char * buff;
  read(fd, buff, sizeof(int *));
  printf("received fd: %d\n", atoi(buff));
  close(fd);
  return 0;
}


/*=========================
  client_handshake
  args: int * to_server

  Perofrms the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  mkfifo("cts", 0600);
  int wkp = open("stc", O_WRONLY);
  *to_server = open("cts", O_CREAT | O_RDWR | O_EXCL, 0600);
  write(wkp, to_server, sizeof(int *));
  return 0;
}
