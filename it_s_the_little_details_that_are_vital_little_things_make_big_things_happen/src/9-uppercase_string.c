/* function changes lowercase letters to uppercase */
char *uppercase_string(char *s)
{
  int i;
  for (i = 0; *(s + i) != '\0'; i++) {
    if (*(s + i) >= 'a' && *(s + i) <= 'z') {
      *(s + i) = (*(s + i) - 32);
    }
  }
  return(s);
}
