/*
Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.

time complexity - O(n^2)
*/
#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertionSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i-1;
    while (key<array[j] && j>=0)
    {
      array[j+1] = array[j];
      --j;
    }
    array[j+1] = key;
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

    insertionSort(arr, size);
    cout<< "Sorted array: " <<endl;
    printArray(arr, size);
    return 0;
}