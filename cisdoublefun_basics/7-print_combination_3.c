int print_char(char c);

void print_combination_3(void) {
  int i;
  int j;
  int k;
  i = 0;
  while (i < 9) {
    j = i + 1;
    while (j < 9) {
      k = j + 1;
      while (k <= 9) {
	print_char(i + 48);
	print_char(j + 48);
	print_char(k + 48);
	if (i < 7) {
	  print_char(',');
	  print_char(' ');
	}
	k++;
      }
      j++;
    }
    i++;
  }
}
