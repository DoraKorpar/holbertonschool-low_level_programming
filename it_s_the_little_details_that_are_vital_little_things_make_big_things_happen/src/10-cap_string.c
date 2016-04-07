/* function capitalizes first letter of word is preceeded by space, \n, or \t */
char *cap_string(char *s) {
  int i;
  for (i = 0; *(s + i) != '\0'; i++) {
    if ((*s >= 'a' && *s <= 'z') 
	|| ((*(s + (i - 1)) == ' ') && *(s + i) >= 'a' && *(s + i) <= 'z')
	|| ((*(s + (i - 1)) == '\n') && *(s + i) >= 'a' && *(s + i) <= 'z')
	|| ((*(s + (i - 1)) == '\t') && *(s + i) >= 'a' && *(s + i) <= 'z')) {
      *(s + i) = (*(s + i) - 32);
    }
  }
  return (s);
}
