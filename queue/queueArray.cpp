/*
Queue follows the First In First Out (FIFO) rule. 
The item that goes in first is the item that comes out first.

Basic operations- enqueue, dequeue, isEmpty, isFull, Peek
*/

// array based implementation
#include<bits/stdc++.h>

using namespace std;

#define MAX_SIZE 101
int A[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
  if(front == -1) return true;
  else return false;
}

bool isFull() {
  if(front ==0 && rear == MAX_SIZE -1) return true;
  else return false;
}

void Enqueue(int x) {
  if(isFull()) {
    cout<<"Error: stack overflow"<<endl;
    return;
  }
  if(front == -1) front = 0;
  rear++;
  A[rear] = x;
}

void Dequeue() {
  if(isEmpty()) {
    cout<<"Error: no elements to pop"<<endl;
    return;
  }
  for (int i = 0; i < rear; i++) {
      A[i] = A[i + 1];
  }
  rear--;
}

int Peek() {
  return A[front];
}

void Print() {
  int i;
  cout<<"Queue: ";
  for ( i = front; i <= rear; i++)
  {
    cout<< A[i] << " ";
  }
  cout<<"\n";
}

int main()
{
  Enqueue(2); Print();
  Enqueue(5); Print();
  Enqueue(10); Print();
  Dequeue();
  Enqueue(12); Print();
  cout<< "Peek: " << Peek();
}