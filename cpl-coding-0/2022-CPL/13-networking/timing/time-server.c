//
// Created by hengxin on 23-1-11.
//

#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
  printf("Configure local address ...\n");

  const struct addrinfo hints = {
      .ai_family = AF_INET,
      .ai_socktype = SOCK_STREAM,
      .ai_flags = AI_PASSIVE,
  };

  struct addrinfo *bind_addr;
  getaddrinfo(NULL, "8080", &hints, &bind_addr);

  printf("Creating socket ...\n");
  int socket_listen = socket(bind_addr->ai_family,
                             bind_addr->ai_socktype,
                             bind_addr->ai_protocol);
  if (socket_listen == -1) {
    fprintf(stderr, "socket() failed. (%d)\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Binding socket to local address ...\n");
  if (bind(socket_listen, bind_addr->ai_addr, bind_addr->ai_addrlen)) {
    fprintf(stderr, "bind() failed. (%d)\n", errno);
    exit(EXIT_FAILURE);
  }
  freeaddrinfo(bind_addr);

  printf("Listening ...\n");
  if (listen(socket_listen, 10) < 0) {
    fprintf(stderr, "listen() failed. (%d)\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Waiting for connections ...\n");
  struct sockaddr_storage client_addr;
  socklen_t client_len = sizeof client_addr;
  int socket_client = accept(socket_listen,
                             (struct sockaddr*) &client_addr,
                             &client_len);
  if (socket_client == -1) {
    fprintf(stderr, "accept() failed. (%d)\n", errno);
    exit(EXIT_FAILURE);
  }

  printf("Client is connected ...\n");
  char address_buffer[100];
  getnameinfo((struct sockaddr*) &client_addr,
              client_len, address_buffer, sizeof address_buffer,
              NULL, 0, NI_NUMERICHOST);
  printf("%s\n", address_buffer);

  printf("Reading request ...\n");
  char request[1024];
  ssize_t bytes_received = recv(socket_client, request, 1024, 0);
  printf("Received %ld bytes.\n", bytes_received);
  printf("%.*s", bytes_received, request);

  printf("Sending response ...\n");
  const char *response =
      "HTTP/1.1 200 OK\r\n"
      "Connection: close\r\n"
      "Content-Type: text/plain\r\n\r\n"
      "Local time is: ";
  ssize_t bytes_sent = send(socket_client, response, strlen(response), 0);
  printf("Send %ld of %zu bytes.\n", bytes_sent, strlen(response));

  time_t timer;
  time(&timer);
  const char *time_msg = ctime(&timer);
  bytes_sent = send(socket_client, time_msg, strlen(time_msg), 0);
  printf("Send %ld of %zu bytes.\n", bytes_sent, strlen(time_msg));

  printf("Closing connection ...\n");
  close(socket_client);

  printf("Closing listening socket ...\n");
  close(socket_listen);

  printf("Finished.\n");
  return 0;
}