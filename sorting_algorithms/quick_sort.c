void quick_sort_parts(int *, int, int);
int partition(int *, int, int);

void quick_sort(int *array, int size)
{
  /* passes the array and first and last indices of array */
  quick_sort_parts(array, 0, (size - 1));
}

void quick_sort_parts(int *array, int first, int last)
{
  int splitpoint;
  
  /* check makes sure array has more than one element */
  if (first < last) {
    /* returns value of index of last pivot */
    splitpoint = partition(array, first, last);

    /* once array is partitioned, func is recursively called
     * passing new values based on previous pivot, determined by partition func */
    quick_sort_parts(array, first, (splitpoint - 1));
    quick_sort_parts(array, (splitpoint + 1), last);
  }
}

int partition(int *array, int first, int last)
{
  int pivot, i, j, temp;
  pivot = array[first];
  i = first + 1;
  j = last;
  while (i < j) {
    /* increment i and j until conditions are met for swapping */
    while (array[i] <= pivot) {
      i++;
    }
    while (array[j] >= pivot) {
      j--;
    }
    /* if i > j, exit loop */
    if (i > j) {}
    else {
      /* swaps values at array indices so larger ones are on right and smaller ones on left */
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  /* switches pivot with last index swapped to put pivot in its correct place in array */
  temp = array[first];
  array[first] = array[j];
  array[j] = temp;
  return j;
}
