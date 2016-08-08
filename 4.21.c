
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>

// OS X 不支持futimens， 使用futimes代替
static int update_file_times(int fd, struct timespec a, struct timespec m) {
#ifdef __APPLE__
  struct timeval times[2];
  times[0].tv_sec = a.tv_sec;
  times[0].tv_usec = a.tv_nsec * 1000;
  times[1].tv_sec = m.tv_sec;
  times[1].tv_usec = m.tv_nsec * 1000;
  return futimes(fd, times);
#else
  struct timespec times[2];
  times[0] = a;
  times[1] = m;
  return futimens(fd, times);
#endif
}

int main(int argc, char const *argv[]) {
  int i, fd;
  struct stat statbuf;
  for (i = 1; i < argc; i++) {
    if (stat(argv[i], &statbuf)) {
      printf("%s : error stat\n", argv[i]);
      return 1;
    }
    if ((fd = open(argv[i], O_CREAT | O_TRUNC)) < 0) {
      printf("%s : open error\n", argv[i]);
      return 1;
    }
    if (update_file_times(fd, statbuf.st_atimespec, statbuf.st_mtimespec) < 0) {
      printf("update file times error\n");
      return 1;
    }
  }
  close(fd);
  return 0;
}
