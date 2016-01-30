#include <unistd.h>
#include <stdio.h>

int main(void)
{
  write (1, "Hello, C\n", 10);
  return(0);
}
