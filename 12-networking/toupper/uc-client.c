/**
 * file: uc-client.c
 * author: hengxin
 * date: 1/18/22
 */

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: time-client hostname port\n");
    return 1;
  }

  printf("Configure remote address ...\n");
  struct addrinfo hints = {
      .ai_socktype = SOCK_STREAM
  };

  struct addrinfo *server_addr;
  if (getaddrinfo(argv[1], argv[2], &hints, &server_addr) != 0) {
    fprintf(stderr, "getaddrinfo() failed\n");
    exit(EXIT_FAILURE);
  }

  char address_buffer[100];
  char service_buffer[100];
  getnameinfo(server_addr->ai_addr, server_addr->ai_addrlen,
              address_buffer, sizeof address_buffer,
              service_buffer, sizeof service_buffer,
              NI_NUMERICHOST);
  printf("Remote address is: %s:%s\n", address_buffer, service_buffer);

  printf("Creating socket ...\n");
  int socket_server = socket(server_addr->ai_family,
                             server_addr->ai_socktype,
                             server_addr->ai_protocol);
  if (socket_server < 0) {
    fprintf(stderr, "socket() failed\n");
    exit(EXIT_FAILURE);
  }

  printf("Connecting ...\n");
  if (connect(socket_server, server_addr->ai_addr, server_addr->ai_addrlen)) {
    fprintf(stderr, "connect() failed\n");
    exit(EXIT_FAILURE);
  }
  freeaddrinfo(server_addr);

  printf("Connected\n");

  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(socket_server, &fds); // watch socket_server to see when there is data
  FD_SET(fileno(stdin), &fds); // watch stdin to see when it has input

  while (1) {
    fd_set read_fds = fds;
    if (select(socket_server + 1, &read_fds, NULL, NULL, NULL) == -1) {
      fprintf(stderr, "select() failed\n");
      exit(EXIT_FAILURE);
    }

    // stdin has input to send to the server
    if (FD_ISSET(fileno(stdin), &read_fds)) {
      char read[4096];
      if (!fgets(read, 4096, stdin))
        break;
      printf("Sending: %s", read);
      int bytes_sent = send(socket_server, read, strlen(read), 0);
      if (bytes_sent == -1) {
        fprintf(stderr, "send() failed\n");
        break;
      }
      printf("Send %d bytes.\n", bytes_sent);
    }

    if (FD_ISSET(socket_server, &read_fds)) {
      char read[4096];
      int bytes_received = recv(socket_server, read, 4096, 0);
      if (bytes_received == -1) {
        fprintf(stderr, "recv() failed\n");
        break;
      } else if (bytes_received == 0) {
        printf(stderr, "The peer has been shutdown.\n");
        close(socket_server);
        socket_server = -1;
        FD_CLR(socket_server, &fds);
      } else {
        printf("Received %d bytes: %.*s",
               bytes_received, bytes_received, read);
      }
    }
  }

  printf("Closing socket ...\n");
  if (socket_server != -1) {
    close(socket_server);
  }

  printf("Finished\n");

  return 0;
}