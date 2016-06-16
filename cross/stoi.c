#include <limits.h>

int string_to_integer(char *s)
{
  long n;
  int m, i, x;

  n = 0;
  m = 0;
  for (x = 0; s[x] != '\0'; x++) {
    /* checks if there is a minus sign */
    if (s[x] == 45) {
      m++;
    }
    /* if char in string is a digit */
    if (s[x] > 47 && s[x] < 58) {
      /* sets i equal to digit instead of ascii value for digit, making it an int */
      i = (s[x] - 48);
      /* accounts for place of digit */
      n = (n*10) + i;
      /* checks if number is out of int range */
      if ((n > INT_MAX && m % 2 == 0) || (n < INT_MIN && m % 2 == 1)) {
	return (1);
      }
      /* if char is string is char */
      if (s[x+1] <= 47 || s[x+1] >= 58){ 
	break; 
      }
    }
  }
  /* if there was an odd number of minus signs, meaning the number is negative */
  if (m % 2 == 1) {
    n = -n; }
  return (n);
}
