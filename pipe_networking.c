#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Perofrms the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
 	mkfifo("wkp", 0600);
  	int wkp = open("wkp", O_RDONLY | O_CREAT | O_EXCL, 0600);
	char * client_stream;
  	read(wkp, client_stream, sizeof(int *));
  	printf("received message through wkp: %d\n", atoi(client_stream));
	close(wkp);

	mkfifo(client_stream, 0600);
	*to_client = open("stc", L, 0600);
	write(


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
  	int wkp = open("wkp", O_WRONLY);
  	*to_server = open("cts", O_CREAT | O_RDWR | O_EXCL, 0600);
  	write(wkp, to_server, sizeof(int *));

	read(

 	return 0;
}

