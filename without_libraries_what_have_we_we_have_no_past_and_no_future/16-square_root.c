int divider(int n, int i);

/* main function that calls helper function */
int square_root(int n) {
  if (n < 0) {
    return(-1);
  }
  return(divider(n, 1));
}

/* uses modulo to make sure only true squares return the root */
int divider(int n, int i) {
  if ((n / i) == i && (n % i) == 0) {
    return(i);
  } 
  if ((n / i) < i) {
    return(-1);
  }
  return(divider(n, ++i));
}
