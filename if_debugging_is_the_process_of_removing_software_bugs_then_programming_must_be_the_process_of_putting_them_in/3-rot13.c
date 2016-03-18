/* function encodes string using rot13 by using ascii table to shift value of character by 13 */
char *rot13(char *s) {
  int i;
  for (i = 0; *(s + i) != '\0'; i++) {
    if ((*(s + i) >= 'a' && *(s + i) <= 'm') || (*(s + i) >= 'A' && *(s + i) <= 'M')) {
      *(s + i) = (*(s + i) + 13);
    } else if ((*(s + i) >= 'n' && *(s + i) <= 'z') || (*(s + i) >= 'N' && *(s + i) <= 'Z')) {
      *(s + i) = (*(s + i) - 13);
    }
  }
  return (s);
}
