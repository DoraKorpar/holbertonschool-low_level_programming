#include "cross_head.h"

void print_cross(int i)
{
  int j;
  
  top_cross(i);
  /* prints middle of cross if i is odd */
  if (i % 2 != 0) {
    middle_space(i);
    print_char('X');
    middle_space(i);
    print_char('\n');
  }
  /* prints middle of cross if i is even */
  else {
    middle_space(i);
    print_char('\\');
    print_char('/');
    middle_space(i);
    print_char('\n');
    middle_space(i);
    print_char('/');
    print_char('\\');
    middle_space(i);
    print_char('\n');
  }
  bottom_cross(i);
}
