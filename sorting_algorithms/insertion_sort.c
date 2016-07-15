void insertion_sort(int * array, int size)
{
  int i, j, tmp;

  i = 1;

  while (i < size) {
    j = i;
    while (j > 0 && array[j] < array[j-1]) {
      tmp = array[j];
      array[j] = array[j-1];
      array[j-1] = tmp;
      j--;
    }
    i++;
  }
}
