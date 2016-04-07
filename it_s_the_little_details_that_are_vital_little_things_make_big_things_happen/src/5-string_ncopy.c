char *string_ncopy(char *dest, const char *src, int n)
{
  int i;
  /* puts src into dest */
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  /* adds null at end of dest */
  for ( ; i < n; i++) {
    dest[i] = '\0';
  }
  return dest;
}
