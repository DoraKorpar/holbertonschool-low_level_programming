#include "my_functions.h"

void print_number_positive(int n)
{
  int printer;
  int power;
  int subtract;
  int multiple;

    while (n > 0) {
      printer = n;
      power = 0;
      /* this while loop determines the power of ten of the first digit of the number input. printer is the integer to be printed. power is the power of ten  */  
      while (printer > 9) {
	  printer = (printer / 10);
	  power++;
	}
      /* this prints the first digit of the number, adding ascii for 0 */
      print_char(printer + 48);
      /* this for loop multiplies out the power of 10 stored in power */
      multiple = 1;
      while (power > 0)	{
	  multiple = (multiple * 10);
	  power--;
	}
      subtract = (printer * multiple);
      n = (n - subtract);
    }
}
void print_number(int n)
{
  if (n > 0) {
      print_number_positive(n);
    }
  else if (n == 0) {
      print_char('0');
    }
  else {
      print_char('-');
      print_number_positive((n * -1));
    }
}
