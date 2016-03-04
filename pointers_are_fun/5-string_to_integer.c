int string_to_integer(char *s)
{
  int x = 0;
  char c;

  while (s[x] != 0) {
    if (s[x] > 47 && s[x] < 58) {
      c = (c + s[x]) - 48;
    }
    else {
      c = 0;
    }
    x++;
  }
  return (c);
}
