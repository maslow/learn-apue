
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char const *argv[]) {
  const int MAXLINE = 1024;
  char buf[1024];
  pid_t pid;
  int status;

  printf("%%  ");
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if(buf[strlen(buf) -1] == '\n')
        buf[strlen(buf) -1] = 0;

    if((pid = fork()) < 0){
      perror("failed to fork process");
      return 0;
    }else if(pid == 0){
      execlp(buf, buf, (char*)0);
      return 127;
    }

    if((pid = waitpid(pid, &status, 0)) <0){
      perror("waitpid");
      return 1;
    }
    printf("%%  ");
  }
  return 0;
}
