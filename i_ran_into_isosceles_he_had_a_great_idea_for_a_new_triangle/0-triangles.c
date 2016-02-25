#include <unistd.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

void triangles_in_the_term(int h, int n) {
  if (h < 1 || n < 1) {}
  else {
    while (n > 0) {
      int numStars = 1, numSpace = h - 1, stars2, space2, height;
      height = h;
      while (height > 0) {
	  space2 = numSpace;
	  while (space2 > 0) {
	      print_char(' ');
	      space2--;
	    }
	  stars2 = numStars;
	  while (stars2 > 0) {
	      print_char('*');
	      stars2--;
	    }
	  numSpace--;
	  numStars += 2;
	  height--;
	  print_char('\n');
      }
      n--;
    }
  }
}
