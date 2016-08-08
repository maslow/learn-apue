
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  if (open("tempfile", O_RDWR | O_CREAT) < 0) {
    printf("open tempfile error\n");
    return 1;
  }
  if (unlink("tempfile") < 0) {
    printf("unlink tempfile error\n");
    return 1;
  }
  printf("file unlinked\n");
  sleep(15);
  printf("done\n");
  return 0;
}
