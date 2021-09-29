#include <bits/stdc++.h>

using namespace std;

class Node
{
  public:
  int data;
  Node* next;
};

int main() {
  // initialize nodes
  Node* head;
  Node* one = NULL;
  Node* two = NULL;
  Node* three = NULL;

  // allocating memory
  one = new Node();
  two = new Node();
  three = new Node();

  // assign data values
  one->data = 1;
  two->data = 2;
  three->data = 3;

  // connecting nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // save first node address in head
  head = one;

  // printing linked list values
  while (head != NULL)
  {
    cout<<head->data<<endl;
    head = head->next;
  }
}