//
// Created by 王福根 on 8/3/16.
//
#include <stdio.h>
#include <unistd.h>

int main(void) {
  int n;
  char buf[1024];
  while ((n = read(STDIN_FILENO, buf, 1024)) > 0)
    if (write(STDOUT_FILENO, buf, n) != n) {
      printf("write error");
      return 1;
    }
  if (n < 0) {
    printf("read error");
    return 1;
  }
  return 0;
}
