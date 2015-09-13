#include "array_utilities.h"

void printArray(int arr[], int size) {
/* Print in square table (10x10) with columns aligned
 */
  int i;

  for (i=0; i < size; i++) {
    printf("%5d ", arr[i]);
    if ((i+1)%10 == 0)
      printf("\n");
  }

  printf("\n");
}
