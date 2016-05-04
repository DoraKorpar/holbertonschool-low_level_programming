int print_char(char c);

void print_alphabet(void) {
  char c;
  c = 'a';
  while (c <= 122) {
    print_char(c);
    c++;
  }
}
