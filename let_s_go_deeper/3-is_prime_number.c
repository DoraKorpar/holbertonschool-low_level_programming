int prime_loop(int n, int i);

int is_prime_number(int n) {
  if (n <= 1) {
    return(0);
  }
  return(prime_loop(n, 2));
}

int prime_loop(int n, int i) {
  if (n % i == 0) {
    return(0);
  }
  if (i > 7) {
    return(1);
  }
  return(prime_loop(n, ++i));
}
