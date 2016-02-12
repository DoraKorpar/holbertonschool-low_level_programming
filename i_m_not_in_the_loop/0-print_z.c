#include "my_functions.h"
#include <unistd.h>

/* There have to be two print_char commands because it can only print one character at a time */
void print_z(void) 
{
  print_char('z');
  print_char('\n');
}



