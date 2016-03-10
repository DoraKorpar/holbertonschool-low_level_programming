int print_char(char c);

void print_string_half(char *str)
{
  int x = 0; int length = 1; 
  while (*(str + x) != '\0') {
    length++;
    x++;
  }
  if (length % 2 == 0) {
    int half = (length / 2); 
    while  (half < length) {
      print_char(*(str + half));
      half++;
    }
  } else {
    int oddHalf = ((length - 1) / 2);  
    while (oddHalf < length) {
      print_char(*(str + oddHalf));
      oddHalf++;
      }
    }
}
