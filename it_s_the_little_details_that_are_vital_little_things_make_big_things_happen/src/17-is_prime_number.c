int prime_loop(int n, int i);

/* calls helper function */
int is_prime_number(int n) {
  if (n <= 1) {
    return(0);
  }
  return(prime_loop(n, 2));
}

/* i starts at 2, so if n is divisible by i then it isn't prime. i stops at seven because that is the last prime number from 0-9 */
int prime_loop(int n, int i) {
  if (n % i == 0) {
    return(0);
  }
  if (i > 7) {
    return(1);
  }
  return(prime_loop(n, ++i));
}
