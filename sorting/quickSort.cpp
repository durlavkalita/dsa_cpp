/*
Quicksort is a sorting algorithm based on the divide and conquer approach where
array is divided into subarrays by selecting a pivot element

time complexity - O(n*logn) - fastest sort() uses this technique
*/
#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
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

    quickSort(arr, 0, size-1);
    cout<< "Sorted array: " <<endl;
    printArray(arr, size);
    return 0;
}