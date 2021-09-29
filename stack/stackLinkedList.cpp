// linked list implementation //
#include<bits/stdc++.h>

using namespace std;

#define MAX 101
int size = 0;

struct Stack {
  int items[MAX];
  int top;
};
typedef struct Stack st;

void createEmptyStack(st *s) {
  s->top = -1;
}

bool isEmpty(st *s) {
  if(s->top == -1) return true;
  else return false;
}

bool isFull(st *s) {
  if (s->top == MAX - 1)
  {
    return true;
  }
  else return false;
  
}

void push(st *s, int x) {
  if (isFull(s)) 
  {
    cout<<"Stack Full"<<endl;
  } else
  {
    s->top++;
    s->items[s->top] = x;
  }
  size++;
}

void pop(st *s) {
  if (isEmpty(s))
  {
    cout<<"Empty Stack"<<endl;
  } else
  {
    cout<<"Item popped: "<<s->items[s->top]<<endl;
    s->top--;
  }
  size--;
}

// Print elements of stack
void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i < size; i++) {
    cout << s->items[i] << " ";
  }
  cout << endl;
}

int main() {
  int ch;
  st *s = new st;

  createEmptyStack(s);

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  printStack(s);

  pop(s);

  cout << "After popping out\n";
  printStack(s);
}