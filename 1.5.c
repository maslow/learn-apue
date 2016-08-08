
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int c;
  while ((c = getc(stdin)) != EOF)
    putc(c, stdout);

  return 0;
}
