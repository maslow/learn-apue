
#include <unistd.h>
#include <stdio.h>

#define BUFFZIE  4096

int main(int argc, char const *argv[]) {
  int n;
  char buf[BUFFZIE];
  while ((n = read(STDIN_FILENO, buf, BUFFZIE)) > 0)
    if(write(STDOUT_FILENO, buf, n) != n){
      perror("write error");
      return 1;
    }

  if (n < 0) {
    printf("read error\n");
    return 1;
  }
  return 0;
}
