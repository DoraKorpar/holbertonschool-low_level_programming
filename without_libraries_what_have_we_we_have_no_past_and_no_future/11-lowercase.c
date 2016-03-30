#include <stdio.h>

char lowercase (char c)
{
  if (c >= 'A' && c <= 'Z')
    {
      return (c + 32);;
    }
  else {
    return (c);
  }
}
