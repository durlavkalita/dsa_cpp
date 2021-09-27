// time complexity - o(n^2)

#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++)
    {
        int swapped = 0; // for optimization
        for (int j = 0; j < size-1; j++)
        {
            if (arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;

                swapped = 1; // array is not sorted
            }
        }
        if (swapped == 0) // array is sorted no need to execute further iterations
        {
            break;
        }
           
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
    int arr[] = {9, 6, 3, 0, -2, -5};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<< "Original array: " <<endl;
    printArray(arr, size);

    bubbleSort(arr, size);
    cout<< "Sorted array: " <<endl;
    printArray(arr, size);
    return 0;
}
