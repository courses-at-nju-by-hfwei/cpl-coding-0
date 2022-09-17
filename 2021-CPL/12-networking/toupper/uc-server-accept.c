/**
 * file: uc-server-accept.c
 * author: hengxin
 * date: 1/18/22
 */

#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
  const char *NAME = NULL;
  const char *SERVICE = "8080";

  /**
   * figure out our local address that our server should bind to
   */
  struct addrinfo hints = {
      .ai_family = AF_INET, // IPv4
      .ai_socktype = SOCK_STREAM, // TCP
      .ai_flags = AI_PASSIVE  // use "0.0.0.0", only for "bind"
  };

  struct addrinfo *bind_addr;
  if (getaddrinfo(NAME, SERVICE, &hints, &bind_addr) != 0) {
    fprintf(stderr, "getaddrinfo() failed\n");
    exit(EXIT_FAILURE); // #include <stdlib.h>
  }

  /**
   * create the socket and get the fd
   */
  printf("Creating socket ...\n");
  int socket_listen = socket(bind_addr->ai_family,
                             bind_addr->ai_socktype,
                             bind_addr->ai_protocol);
  if (socket_listen == -1) {
    fprintf(stderr, "socket() failed.");
    exit(EXIT_FAILURE);
  }

  /**
   * bind socket to local address
   */
  printf("Binding socket to local address ...\n");
  if (bind(socket_listen, bind_addr->ai_addr, bind_addr->ai_addrlen) != 0) {
    fprintf(stderr, "bind() failed.");
    exit(EXIT_FAILURE);
  }
  freeaddrinfo(bind_addr);

  /**
   * start listening for connections
   */
  printf("Starting listening ...\n");
  if (listen(socket_listen, 10) != 0) {
    fprintf(stderr, "listen() failed.\n");
    exit(EXIT_FAILURE);
  }

  /**
   * accept incoming connection
   */
  printf("Waiting for connection ...\n");
  struct sockaddr_storage client_addr;
  socklen_t client_len = 0;

  while (1) {
    client_len = sizeof(client_addr);
    int socket_client = accept(socket_listen,
                               (struct sockaddr *) &client_addr,
                               &client_len);
    if (socket_client == -1) {
      fprintf(stderr, "accept() failed.\n");
      exit(EXIT_FAILURE);
    }

    /**
     * A TCP connection has been established to a remote client.
     * Print the client's address.
     */
    char address_buffer[100];
    char service_buffer[100];
    getnameinfo((struct sockaddr *) &client_addr, client_len,
        address_buffer, sizeof address_buffer,
        service_buffer, sizeof service_buffer,
        NI_NUMERICHOST);
    printf("Client %s:%s is connected.\n",
           address_buffer, service_buffer);

    /**
     * receive data from the client
     */
    printf("Receive text ...\n");
    char text[1024];
    ssize_t bytes_received = recv(socket_client, text, sizeof text, 0);
    printf("Received %zd bytes:\n%.*s.\n", bytes_received,
           (int) bytes_received, text);

    /**
     * send the response
     */
    printf("Sending response ...\n");
    const char *response =
        "HTTP/1.1 200 OK\r\n"
        "Connection: close\r\n"
        "Content-Type : text/plain\r\n\r\n";
    int bytes_sent = send(socket_client, response, strlen(response), 0);
    printf("Send %d of %d bytes.\n",
           bytes_sent, (int) strlen(response));

    for (int i = 0; i < bytes_received; i++) {
      text[i] = toupper(text[i]);
    }

    bytes_sent = send(socket_client, text, strlen(text), 0);
    printf("Send %d of %d bytes.\n", bytes_sent, (int) strlen(text));

    /**
     * Close the connection to the client
     * to indicate that we have sent all data
     */
    printf("Closing connection ...\n");
    close(socket_client);
  }

  /**
   * Closing the listening socket
   */
  printf("Closing listening socket ...\n");
  close(socket_listen);

  printf("Finished.\n");

  return 0;
}