/*store value of *a in extra variable to it can be reassigned to *b*/
void swap_int(int *a, int *b)
{
  int c = *a;
  *a = *b;
  *b = c;
}
