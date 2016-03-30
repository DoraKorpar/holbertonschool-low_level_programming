int print_char(char c);

void print_string_2(char *str)
{
  int x = 0;
  while (*(str + x) != '\0') {
    if (x % 2 == 0) {
      print_char(*(str + x));
    }
    x++;
  }
}
