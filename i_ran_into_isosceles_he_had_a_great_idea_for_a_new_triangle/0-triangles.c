#include <unistd.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

void triangles_in_the_term(int h, int n) {
  if (h < 1 || n < 1) {}
  else {
    while (n > 0) {
      int numStars = 1, numSpace = h - 1, otherStars, otherSpace;
      while (h > 0) {
	  otherSpace = numSpace;
	  while (otherSpace > 0) {
	      print_char(' ');
	      otherSpace--;
	    }
	  otherStars = numStars;
	  while (otherStars > 0) {
	      print_char('*');
	      otherStars--;
	    }
	  numSpace--;
	  numStars += 2;
	  h--;
	  print_char('\n');
      }
      n--;
    }
  }
}
