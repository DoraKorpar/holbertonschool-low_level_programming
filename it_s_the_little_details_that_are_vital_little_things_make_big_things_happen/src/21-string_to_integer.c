#include <limits.h>

int string_to_integer(char *s)
{
  long n = 0;
  int m = 0, i, x = 0;
  
  while (*(s+x) != '\0') {
    if (*(s+x) == 45) {
      m++;
    }
    if (*(s+x) > 47 && *(s+x) < 58) {
      i = (*(s+x) -48);
      n = (n*10) + i; 
      if ((n > INT_MAX && m % 2 == 0) || (n < INT_MIN && m % 2 == 1)) {
	return (0);
      }
      if (*(s+x+1) <= 47 || *(s+x+1) >= 58){ 
	break; 
      }
    }
    x++;
  } 
  if (m % 2 == 1) {
    n = -n; }
  return (n);
}
