int print_char(char c);

void print_tebahpla(void) {
  char c;
  c = 'z';
  while (c > 96) {
    print_char(c);
    c--;
  }
}
