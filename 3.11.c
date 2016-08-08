
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int val;
  if (argc != 2) {
    printf("usage: 3.11 <descriptor#>\n");
    return 1;
  }

  if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
    printf("fcntl error for fd %d\n", atoi(argv[1]));
    return 1;
  }

  switch (val & O_ACCMODE) {
  case O_RDONLY:
    printf("read only\n");
    break;

  case O_WRONLY:
    printf("write only\n");
    break;

  case O_RDWR:
    printf("read and write\n");
    break;

  default:
    printf("unknown access mode\n");
    return 1;
  }

  if (val & O_APPEND)
    printf(" append ");

  if (val & O_NONBLOCK)
    printf(" nonblock ");

  if (val & O_SYNC)
    printf(" synchronous writes ");

  return 0;
}
