char *string_copy(char *dest, const char *src)
{
  int i = 0, j;
  /* only need one loop because dest is empty */
  for (j = 0; src[j] != '\0'; j++, i++) {
    dest[i] = src[j];
  }
  dest[i] = '\0';
  return dest;
}
