
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

static void sig_int(int);

int main(int argc, char const *argv[]) {
  const int MAXLINE = 128;
  char buf[MAXLINE];

  if (signal(SIGINT, sig_int) == SIG_ERR) {
    perror("signal");
    return 1;
  }

  printf("%%  ");
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }
    pid_t pid;
    if ((pid = fork()) < 0) {
      printf("error fork\n");
      return 1;
    } else if (pid == 0) {
      execlp(buf, buf, NULL);
      return 0;
    }
    int status;
    if ((pid = waitpid(pid, &status, 0)) < 0) {
      perror("waitpid");
      return 1;
    }
    printf("%%  ");
  }
  printf("bye\n");
  return 0;
}

void sig_int(int signo) { printf("sig_int %d\n", signo); }
