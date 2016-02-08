#include "my_functions.h"

//base16 goes from 0-F, so I just broke it up into two for loops
void print_base16(void)
{
  char c;
  for(c='0'; c<='9'; c++)
    {
      print_char(c);
    }
  for(c='A'; c<='F'; c++)
    {
      print_char(c);
    }
}
