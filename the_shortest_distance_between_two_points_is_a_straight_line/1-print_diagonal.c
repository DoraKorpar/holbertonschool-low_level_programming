int print_char(char c);

void print_diagonal(int n)
{
  int numSpace = 0, space2;
  if (n <=  0) {
    print_char('\n');
  } else {
    while (n > 0) {
      space2 = numSpace;
      while (space2 > 0) {
	print_char(' ');
	space2--;
      }
    print_char('\\');
    print_char('\n');
    n--;
    numSpace++;
  }
}







}
