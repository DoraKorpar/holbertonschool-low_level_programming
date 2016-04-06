void array_iterator(int *p, int i, void (*action_func)(int)) {
  int j;
  for (j = 0; j < i; j++) {
    (*action_func)(p[j]);
  }
}
