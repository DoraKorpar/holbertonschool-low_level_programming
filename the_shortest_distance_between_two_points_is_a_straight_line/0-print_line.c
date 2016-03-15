int print_char(char c);
void print_line(int n)
{
  while (n > 0)
    {
      print_char('_');
      n--;
    }
  print_char('\n');
}
