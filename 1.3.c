
#include <stdio.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
  DIR             *dp;
  struct dirent   *dirp;
  char            *cmd;
  if(2 == argc)
    cmd = (char*)argv[1];
  else
    cmd = ".";

  if((dp = opendir(cmd)) == NULL)
  {
    printf("Cannot open dir:%s\n", cmd);
    return 1;
  }

  while((dirp = readdir(dp)) != NULL)
    printf("%s\t", dirp->d_name);

  printf("\n");
  return 0;
}
