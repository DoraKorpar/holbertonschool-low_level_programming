void bubble_sort(int *array, int size)
{
  int i, tmp, loop;

  i = 0;
  /* loop is one less than size b/c array starts at 0 */
  loop = size - 1;
  while (loop > 0) {
    while ((i + 1) < size) {
      if (array[i] > array[i + 1]) {
		  /* switches number at array indeces if conditions are met */
		  tmp = array[i];
		  array[i] = array[i + 1];
		  array[i + 1] = tmp;
      }
      i++;
    }
    /* i reinitialized to 0 to restart at beginning of array for every loop */
    i = 0;
    loop--;
  }
}
