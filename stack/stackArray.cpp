/*
A stack is a linear data structure that follows the principle of Last In First Out (LIFO). 
This means the last element inserted inside the stack is removed first.
Basic operations - Push, Pop, isEmpty, isFull, Peek/Top
*/

// array implementation

#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

bool isEmpty() {
  if(top == -1) return true;
  else return false;
}

bool isFull() {
  if(top == MAX_SIZE -1) return true;
  else return false;
}

void Push(int x) {
  if(isFull()) {
    cout<<"Error: stack overflow"<<endl;
    return;
  }
  A[++top] = x;
}

void Pop() {
  if(isEmpty()) {
    cout<<"Error: no elements to pop"<<endl;
    return;
  }
  top--;
}

int Top() {
  return A[top];
}

void Print() {
  int i;
  cout<<"Stack: ";
  for ( i = 0; i <= top; i++)
  {
    cout<< A[i] << " ";
  }
  cout<<"\n";
}

int main()
{
  Push(2); Print();
  Push(5); Print();
  Push(10); Print();
  Pop();
  Push(12); Print();
  cout<< "Top: " << Top();
}

