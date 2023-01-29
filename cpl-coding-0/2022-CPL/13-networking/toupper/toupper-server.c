//
// Created by hengxin on 23-1-11.
//

#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
int main() {
  printf("Configuring local address ...\n");
  struct addrinfo hints = {
      .ai_family = AF_INET,
      .ai_socktype = SOCK_STREAM,
      .ai_flags = AI_PASSIVE,
  };

  struct addrinfo *server_addr;
  getaddrinfo(NULL, "8080", &hints, &server_addr);

  printf("Creating socket ...\n");
  int socket_listen = socket(server_addr->ai_family,
                             server_addr->ai_socktype,
                             server_addr->ai_protocol);
  if (socket_listen == -1) {
    printf("socket() failed with errno = %d.\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Binding socket to local address ...\n");
  if (bind(socket_listen, server_addr->ai_addr, server_addr->ai_addrlen)) {
    printf("bind() failed with errno = %d.\n", errno);
    exit(EXIT_FAILURE);
  }
  freeaddrinfo(server_addr);

  printf("Listening ...\n");
  if (listen(socket_listen, 10) < 0) {
    printf("listen() failed with errno = %d.\n", errno);
    exit(EXIT_FAILURE);
  }

  fd_set master;
  FD_ZERO(&master);
  FD_SET(socket_listen, &master);
  int max_socket = socket_listen;

  printf("Waiting for connections ...\n");
  while (true) {
    fd_set reads = master;
    if (select(max_socket + 1, &reads, NULL, NULL, NULL) < 0) {
      printf("select() failed with errno = %d\n", errno);
      exit(EXIT_FAILURE);
    }

    for (int socket = 1; socket <= max_socket; socket++) {
      if (FD_ISSET(socket, &reads)) {
        if (socket == socket_listen) {
          struct sockaddr_storage client_addr;
          socklen_t client_addr_len = sizeof client_addr;
          int socket_client = accept(socket_listen,
                                     (struct sockaddr*) &client_addr,
                                     &client_addr_len);
          if (socket_client == -1) {
            printf("accept() failed with errno = %d\n", errno);
            exit(EXIT_FAILURE);
          }

          FD_SET(socket_client, &master);
          if (socket_client > max_socket) {
            max_socket = socket_client;
          }

          char addr_buffer[100];
          getnameinfo((struct sockaddr*) &client_addr, client_addr_len,
                      addr_buffer, sizeof addr_buffer,
                      NULL, 0, NI_NUMERICHOST);
          printf("New connection from %s\n", addr_buffer);
        } else {
          char read[1024];
          int bytes_received = recv(socket, read, 1024, 0);
          if (bytes_received < 1) {
            FD_CLR(socket, &master);
            close(socket);
            continue;
          }

          for (int i = 0; i < bytes_received; i++) {
            read[i] = toupper(read[i]);
          }
          send(socket, read, bytes_received, 0);
        }
      }
    }
  }

  printf("Closing listening socket ...\n");
  close(socket_listen);

  printf("Finished.\n");
  exit(EXIT_SUCCESS);
}