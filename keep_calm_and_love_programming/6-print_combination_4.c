#include "my_functions.h"

void print_combination_4(void)
{
  int n, i , j, k;
  for (n = 0; n <= 9; n++)
    {
      for (i = 0; i <= 9; i++)
	{
	  for (j = 0; j <= 9; j++)
	    {
	      for (k = (n + i + 1); k <= 9; k++)
		{
		  print_char(n + 48);
		  print_char(i + 48);
		  print_char(' ');
		  print_char(j + 48);
		  print_char(k + 48);
		  print_char(',');
		  print_char(' ');
		  /* if (n < 9 && i < 9 && j < 9 && k < 9)
		         {
			       print_char(',');
			             print_char(' ');
				     }*/
		}
	    }
	}
    }
}

