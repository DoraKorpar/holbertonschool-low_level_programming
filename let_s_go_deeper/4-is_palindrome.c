int string_length(char *s, int i);
int compare_strings(char *s, int i, int j);

int is_palindrome(char *s) {
  int i = string_length(s, 0);
  return(compare_strings(s, --i, 0));
}

int string_length(char *s, int i) {
  if (s[i] == 0) {
    return(i);
  }
  return(string_length(s, ++i));
}

int compare_strings(char *s, int i, int j) {
  if (s[j] != s[i]) {
    return(0);
  }
  if (j == i || j > i) {
    return(1);
  }
  return(compare_strings(s, --i, ++j));
}
