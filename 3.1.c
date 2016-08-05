
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    printf("cannot seek\n");
  else
    printf("seek OK\n");
  return 0;
}
