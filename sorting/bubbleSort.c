#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int num);

int main() {
  int num;

  printf("Enter the number of elements: ");
  scanf("%d", &num);

  int *arr = (int *)malloc(num * sizeof(int));

  if (arr == NULL) {
    printf("Memory Allocation Failed!\n");
    return -1;
  }

  for (int i = 0; i < num; i++) {
    printf("Enter the element at index %d: ", i);
    scanf("%d", &arr[i]);
  }

  bubbleSort(arr, num);

  printf("Sorted Array: \n");
  for (int i = 0; i < num; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");

  return 0;
}

void bubbleSort(int *arr, int num) {
  int temp, swap;

  /*
   * Use of swap:
   * In case the array is {42, 21, 13, 34, 65, 51},
   * Pass 1: Iteration 1: we get array = {21, 42, 13, 34, 65, 51}
   * Pass 1: Iteration 2: we get array = {21, 13, 42, 34, 65, 51}
   * Pass 1: Iteration 3: we get array = {21, 13, 34, 42, 65, 51}
   * Pass 1: Iteration 4: we get array = {21, 13, 34, 42, 65, 51}
   * Pass 1: Iteration 5: we get array = {21, 13, 34, 42, 51, 65}
   *
   * Pass 2: Iteration 1: we get array = {13, 21, 34, 42, 51, 65}
   * No more iterations or passes are needed. The extra loops we perform are
   * wastage of resources.
   *
   * Hence, we introduce swap element. It checks for swap value after the
   * completion of a pass. After each pass, if swap == 0, then no more passes
   * are required. Hence, we break the loop.
   */

  for (int i = num - 1; i > 0; i--) {
    swap = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swap++;
      }
    }
    if (swap == 0) {
      break;
    }
  }
}
