void bubble_sort(int *array, int size)
{
  int i, tmp, loop;

  i = 0;
  loop = size - 1;

  while (loop > 0) {
    while ((i + 1) < size) {
      if (array[i] > array[i + 1]) {
	tmp = array[i];
	array[i] = array[i + 1];
	array[i + 1] = tmp;
      }
      i++;
    }
    i = 0;
    loop--;
  }
}
