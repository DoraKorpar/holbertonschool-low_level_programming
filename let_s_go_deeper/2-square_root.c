int square_root(int n) {
  int i = 0;
  if (n < 0) {
    return(-1);
  }
  if ((n / i) == i) {
    return(i);
  }
  return(square_root(i+1));
}
