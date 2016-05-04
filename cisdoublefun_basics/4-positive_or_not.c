int print_char(char c);

void positive_or_not(int n) {
  if (n == 0) {
    print_char('Z');
  }
  else if (n > 0) {
    print_char('P');
  }
  else {
    print_char('N');
  }
}
