#include<bits/stdc++.h>

using namespace std;

void binarySearch(int a[], int size, int data) {
  int pos = -1;
  int low = 0;
  int high = size;

  while (low <= high)
  {
    int mid = low + (high-low)/2;

    if(a[mid] == data) {pos = mid; break;}

    else if(a[mid] < data) { low = mid+1;}

    else {high = mid-1;}
  }
  
  if (pos != -1)
  {
    cout<< "Element " << data << " is found in the array at position " << pos+1 <<endl;
  }
  else {
    cout<< "Element not found."<<endl;
  }
}

void printArray(int a[], int size) {
  for (int i = 0; i < size; i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<"\n";
}

int main()
{
  int a[] = {-2,-4,0,2,-1,6,3};
  int size = sizeof(a)/sizeof(a[0]);

  cout<<"Array: "<<endl;
  printArray(a, size);

  sort(a, a+size);
  cout<<"Sorted array: "<<endl;
  printArray(a, size);

  int n;
  cout<<"Enter element to search: "<<endl;
  cin>>n; 

  binarySearch(a, size, n);
}