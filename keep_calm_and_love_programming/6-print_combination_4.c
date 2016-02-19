#include "my_functions.h"

void print_combination_4(void)
{
  int n, i;
  for (n = 0; n < 99; n++)
    {
      for (i = n + 1; i <= 99; i++)
	{
	  print_char((n / 10) + 48);
	  print_char((n % 10) + 48);
	  print_char(' ');
	  print_char((i / 10)  + 48);
	  print_char((i % 10) + 48);
	  print_char(',');
	  print_char(' ');
	}
    }
}

