char *concat_strings(char *dest, const char *src)
{
  int i,  j;
  /* first for loop stores length of dest in i */
  for (i = 0; dest[i] != '\0'; i++);
  /* second for loop assigns src to dest beginning at stored i value */
  for (j = 0; src[j] != '\0'; j++, i++) {
    dest[i] = src[j];
  }

  dest[i] = '\0';
  return (dest);
}