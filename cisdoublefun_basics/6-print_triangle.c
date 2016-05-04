int print_char(char c);

void print_triangle(int n) {
  int i;
  int icopy;
  int ncopy;
  i = 0;
  icopy = i;
  ncopy = (n - 1);
  if (n == 1) {
    print_char('\n');
    print_char('*');
    print_char('\n');
  }
  if (n > 1) { 
    while (i <= ncopy) {
      while (icopy > 0) {
	print_char('*');
	icopy--;
      }
      print_char('\n');
      i++;
      icopy = i;
    }
    while (i > 0) {
      while (icopy > 0) {
        print_char('*');
        icopy--;
      }
      print_char('\n');
      i--;
      icopy = i;
    }
  }
  print_char('\n');
}
