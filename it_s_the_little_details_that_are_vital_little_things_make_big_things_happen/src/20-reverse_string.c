/* reorders array to be backwards */
void reverse_string(char *s)
{
  char temp;
  int i, j;

  i = 0;
  j = 0;

  while (s[j] != 0) {
    j++;
  }
  j--;
  while (i < j) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++;
    j--;
  }
}
