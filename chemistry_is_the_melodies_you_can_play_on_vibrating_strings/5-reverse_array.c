void reverse_array(int *a, int n)
{
  /* temp variable is used to store one value of the array and then assigns it to the reverse value */
  int temp, i = 0, j = (n - 1);
  while (i < j) {
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    i++;
    j--;
  }
}
