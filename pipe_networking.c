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
  	int wkp = open("wkp", O_RDONLY | O_CREAT, 0600);
	if(wkp == -1){
	  printf("[server] error opening Well Known Pipe: %s\n", strerror(errno));
	  exit(0);
	} else {
	  printf("[server] wkp successfully opened!!\n");
	}
	char * client_stream = malloc(sizeof(char) * 100);
  	read(wkp, client_stream, sizeof(client_stream));
  	printf("[server] received message through wkp: %s\n", client_stream);
	//close(wkp);
	//remove("wkp");

	//mkfifo(client_stream, 0600);
	*to_client = malloc(sizeof(int));
	*to_client = open(client_stream, O_WRONLY);
	if(*to_client == -1){
	  printf("[server] error opening %s: %s\n", client_stream, strerror(errno));
	  exit(0);
	} else {
	  printf("[server] successfully opened cts!!\n");
	}
	char * message = "hello!!";
	write(*to_client, message, sizeof(message));
	printf("[server] sending message through %s: %s\n", client_stream, message);
	free(client_stream);
  	return wkp;
}


/*=========================
  client_handshake
  args: int * to_server

  Perofrms the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
        *to_server = malloc(sizeof(int));
        *to_server = open("wkp", O_WRONLY);
	if(*to_server == -1){
	  printf("[client] error opening wkp: %s\n", strerror(errno));
	  exit(0);
	} else {
	  printf("[client] wkp successfully opened!!\n");
	}
	char * name = "cts";
  	mkfifo(name, 0600);
  	write(*to_server, name, sizeof(name));
	printf("[client] sending message through wkp: %s\n", name);

	int cts = open("cts", O_CREAT | O_RDONLY , 0600);
	if(cts == -1) {
	  printf("[client] error creating/opening cts: %s\n", strerror(errno));
	} else {
	  printf("[client] cts successfully created!!\n");
	}
	char * server_stream = malloc(sizeof(char) * 100);
	read(cts, server_stream, sizeof(server_stream));
	printf("[client] received message from server: %s\n", server_stream);
	free(server_stream);
	//close(cts);
	//remove("cts");

	return cts;
}

