//
// Created by hengxin on 23-1-11.
//

#include <ifaddrs.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  struct ifaddrs *addrs;
  if (getifaddrs(&addrs) == -1) {
    printf("getifaddrs() failed.\n");
    exit(EXIT_FAILURE);
  }

  struct ifaddrs *addr = addrs;
  while (addr) {
    int family = addr->ifa_addr->sa_family;
    if (family == AF_INET || family == AF_INET6) {
      printf("%s\t", addr->ifa_name);
      printf("%s\t", family == AF_INET ? "IPv4" : "IPv6");

      char ap[100];
      const int family_size =
          family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
      getnameinfo(addr->ifa_addr, family_size, ap, sizeof ap, 0, 0, NI_NUMERICHOST);
      printf("\t%s\n", ap);
    }
    addr = addr->ifa_next;
  }

  freeifaddrs(addrs);
  exit(EXIT_SUCCESS);
}