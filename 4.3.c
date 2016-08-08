
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  struct stat buf;
  char *str;
  for (size_t i = 1; i < argc; i++) {
    printf("%s:  ", argv[i]);
    if (lstat(argv[i], &buf) < 0) {
      printf("lstat error\n");
      continue;
    }
    if (S_ISREG(buf.st_mode))
      str = "regular";
    else if (S_ISDIR(buf.st_mode))
      str = "directory";
    else if (S_ISCHR(buf.st_mode))
      str = "character";
    else if (S_ISBLK(buf.st_mode))
      str = "block special";
    else if (S_ISFIFO(buf.st_mode))
      str = "pipe or FIFO";
    else if (S_ISLNK(buf.st_mode))
      str = "symbolic link";
    else if (S_ISSOCK(buf.st_mode))
      str = "socket";
    else
      str = "Unknown File Type";

    printf("%s\n", str);
  }
  return 0;
}
