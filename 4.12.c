
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  struct stat statbuf;

  if (stat("foo", &statbuf) < 0) {
    printf("stat foo error\n");
    return 1;
  }
  if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
    printf("chmod foo error\n");
    return 1;
  }
  if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0) {
    printf("chmod bar error\n");
    return 1;
  }
  printf("sizeof foo is %lld\n", statbuf.st_size);
  return 0;
}
