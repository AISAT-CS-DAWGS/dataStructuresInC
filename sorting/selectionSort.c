#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int n);

int main() {
  int num;

  printf("Enter the number of elements: ");
  scanf("%d", &num);

  int *arr = (int *)malloc(num * sizeof(int));

  for (int i = 0; i < num; i++) {
    printf("Enter the element at index %d: ", i);
    scanf("%d", &arr[i]);
  }

  selectionSort(arr, num);

  printf("Sorted Array: \n");
  for (int i = 0; i < num; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

void selectionSort(int *arr, int n) {
  int temp, minIndex;

  for (int i = 0; i < n - 1; i++) {
    minIndex = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (i != minIndex) {
      temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}
