int print_char(char c);

void print_diagonal(int n)
{
  int spaces = 0, n2 = n;
  if (n > 0) {
  while (n > 0) {
    if (spaces < n2) {
      print_char(' ');
      spaces++;
    }
    print_char('\\');
    print_char('\n');
    n--;
  }
}
  else {
    print_char('\n');
}
}
