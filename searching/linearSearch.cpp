#include<bits/stdc++.h>

using namespace std;

void linearSearch(int a[], int size, int data) {
  int pos = -1;
  for (int i = 0; i < size; i++)
  {
    if (a[i] == data){
      pos = i;
      break;
    }
  }
  if (pos != -1)
  {
    cout<< "Element " << data << " is found in the array at position" << pos+1 <<endl;
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

  int n;
  cout<<"Enter element to search: "<<endl;
  cin>>n; 

  linearSearch(a, size, n);
}