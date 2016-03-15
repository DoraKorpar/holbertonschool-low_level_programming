char *nconcat_strings(char *dest, const char * src, int n)
{
  int i, j;
  /* first for loop stores length of dest in i */
  for (i = 0; dest[i] != '\0'; i++);
  /* appends src up to number of characters n to dest */
  for (j = 0 ; j < n && src[j] != '\0' ; j++, i++) {
    dest[i] = src[j];
  }
  dest[i] = '\0';
  return dest;
}
