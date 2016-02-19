#include "my_functions.h"

void print_combination_2(void)
{
  int n;
  int i;
  /* this for loop determines the first digit of the number */
  for (n = 0; n <= 9; n++)
    {
      /* this for loop determines the second digit of the number and prints everything */
      for (i = n + 1; i <= 9; i++)
	{
	  print_char((n + 48));
	  print_char((i + 48));
	  /* no comma after 89! */
	  if (n < 8)
	    {
	      print_char(',');
	      print_char(' ');
	    }
	}
    }
}    
