
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int fd;
  if (argc != 2) {
    printf("usage: 4.8 <pathname>\n");
    return 1;
  }
  if (access(argv[1], R_OK) < 0) {
    printf("File can not be read: %s\n", argv[1]);
    return 1;
  }
  if ((fd = open(argv[1], O_RDONLY)) < 0) {
    printf("open file error\n");
    return 1;
  } else {
    printf("Success to open for reading:%d\n", fd);
  }
  return 0;
}
