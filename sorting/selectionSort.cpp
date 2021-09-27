/*
Selection sort is a sorting algorithm that selects the smallest element from an unsorted list in each iteration 
and places that element at the beginning of the unsorted list.

time complexity - O(n^2)
*/
#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < size; j++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[j] < array[min_idx])
        min_idx = j;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[i]);
  }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout<< arr[i] << " ";
    }
    cout<< "\n";
}

int main()
{
    int arr[] = {9, -2, 3, 0, 6, -5};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<< "Original array: " <<endl;
    printArray(arr, size);

    selectionSort(arr, size);
    cout<< "Sorted array: " <<endl;
    printArray(arr, size);
    return 0;
}