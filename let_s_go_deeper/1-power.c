/* multiplies x recursively y number of times */

int power(int x, int y){
  if (x < 0) {
    return(-1);
  }
  if (y < 0) {
    return(-1);
  }
  if (y < 1) {
    return(1);
  }
  return (x * power(x, --y));
}
