int print_char(char c);

void print_base16(void) {
  int i;
  i = 48;
  while (i < 58) {
    print_char(i);
    i++;
  }
  i = 65;
  while (i < 71) {
    print_char(i);
    i++;
  }
}
