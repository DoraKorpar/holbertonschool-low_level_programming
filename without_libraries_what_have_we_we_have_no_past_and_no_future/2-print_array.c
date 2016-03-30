void print_char(char c);
void print_positive(int n);
void print_number(int n);

void print_array(int *a, int n)
{
  int x = 0;
  while (x <= n-1) {
    if (x == n-1) {
      print_number(a[x]);
      print_char('\n');
    } else {
      print_number(a[x]);
      print_char(',');
      print_char(' ');
    }
    x++;
  }
}

void print_number(int n)
{
  if (n > 0) {
    print_positive(n);
  }
  else if (n == 0) {
    print_char('0');
  }
  else {
    print_char('-');
    n = -n;
    print_positive(n);
  }
}

void print_positive(int n)
{
  int print_me; int power; int digit;
  digit = n;
  power = 1;
  while (digit > 9) {
    digit /= 10;
    power *= 10;
  }
  while (n > 0) {
    print_me = n / power;
    n = n % power;
    power /= 10;
    print_char(print_me + '0');
  }
}
