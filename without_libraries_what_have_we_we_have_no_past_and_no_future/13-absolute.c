/* This function returns an int, so that's all that has to be done*/
int absolute(int n)
{
  if (n > 0) {
    return(n);
  }
  else if (n == 0) {
    return(0);
  }
  else {
    return(-n);
  }
}
