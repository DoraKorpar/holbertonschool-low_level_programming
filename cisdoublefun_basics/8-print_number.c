int print_char(char c);
void print_positive(int n);

void print_number(int n) {
  if (n == 0) {
    print_char('0');
  }
  if (n > 0) {
    print_positive(n);
  }
  if (n < 0) {
    print_char('-');
    n = -n;
    print_positive(n);
  }
}

void print_positive(int n) {
  int ncopy;
  int power;
  int print_me;
  ncopy = n;
  power = 1;
  while (ncopy > 9) {
    ncopy /= 10;
    power *= 10;
  }
  while (n > 0) {
    print_me = n / power;
    n = n % power;
    power /= 10;
    print_char(print_me + 48);
  }
}
