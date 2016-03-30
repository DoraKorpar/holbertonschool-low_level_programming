int print_char(char c);

/* I think this is possible with just if statements, but this is nicer */
void positive_or_not(int n)
{
  if (n > 0)
    {
      print_char('P');
    }
  else if (n < 0)
    {
      print_char('N');
    }
  else 
    {
      print_char('Z');
    }
}
