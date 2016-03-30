int string_length(char *s, int i);
int compare_strings(char *s, int i, int j);

/* calls two helper functions */
int is_palindrome(char *s) {
  int i = string_length(s, 0);
  return(compare_strings(s, --i, 0));
}

/* find length of string */
int string_length(char *s, int i) {
  if (s[i] == 0) {
    return(i);
  }
  return(string_length(s, ++i));
}

/* compares first and last characters of strings, moving inward. if i == j terminates recursion for string with odd number of characters, if j > i terminates recursion string with even number of characters */
int compare_strings(char *s, int i, int j) {
  if (s[j] != s[i]) {
    return(0);
  }
  if (j == i || j > i) {
    return(1);
  }
  return(compare_strings(s, --i, ++j));
}
