
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(int argc, char const *argv[]) {
  int fd;
  if ((fd = creat("file.hole", FILESEC_MODE)) < 0) {
    perror("cannot create file");
    return 1;
  }
  if (write(fd, buf1, 10) != 10) {
    perror("error file write");
    return 1;
  }
  if (lseek(fd, 1024, SEEK_SET) == -1) {
    perror("cannot seek");
    return 1;
  }

  if (write(fd, buf2, 10) != 10) {
    perror("error to write file");
    return 1;
  }
  return 0;
}
