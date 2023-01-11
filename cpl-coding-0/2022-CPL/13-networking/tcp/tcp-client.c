//
// Created by hengxin on 23-1-11.
//

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: tcp-client hostname port\n");
    exit(EXIT_FAILURE);
  }

  printf("Configuring remote address ...\n");
  struct addrinfo hints = {
      .ai_socktype = SOCK_STREAM,
  };
  struct addrinfo *server_addr;
  getaddrinfo(argv[1], argv[2], &hints, &server_addr);

  printf("Remote server address is ...\n");
  char addr_buffer[100];
  char service_buffer[100];
  getnameinfo(server_addr->ai_addr,
              server_addr->ai_addrlen,
              addr_buffer, sizeof addr_buffer,
              service_buffer, sizeof service_buffer,
              NI_NUMERICHOST);
  printf("%s\t%s\n", addr_buffer, service_buffer);

  printf("Creating socket ...\n");
  int socket_client = socket(server_addr->ai_family,
                             server_addr->ai_socktype,
                             server_addr->ai_protocol);
  printf("Connecting ...\n");
  if (connect(socket_client, server_addr->ai_addr, server_addr->ai_addrlen)) {
    fprintf(stderr, "connect() failed (%d)\n", errno);
    exit(EXIT_FAILURE);
  }
  freeaddrinfo(server_addr);

  printf("Connected.\n");
  printf("To send data, enter text followed by enter.\n");
  while (true) {
    fd_set reads;
    FD_ZERO(&reads);
    FD_SET(fileno(stdin), &reads);
    FD_SET(socket_client, &reads);

    select(socket_client + 1, &reads, NULL, NULL, NULL);
    if (FD_ISSET(socket_client, &reads)) {
      char read[4096];
      int bytes_received = recv(socket_client, read, 4096, 0);
      if (bytes_received < 1) {
        printf("Connection closed by peer.\n");
        break;
      }
      printf("Received (%d bytes): %.*s",
             bytes_received, bytes_received, read);
    }

    if (FD_ISSET(0, &reads)) {
      char read[4096];
      if (!fgets(read, 4096, stdin)) {
        break;
      }
      printf("Sending: %s", read);
      int bytes_sent = send(socket_client, read, strlen(read), 0);
      printf("Send %d bytes.\n", bytes_sent);
    }
  }

  printf("Closing socket ...\n");
  close(socket_client);

  printf("Finished.\n");
  exit(EXIT_SUCCESS);
}