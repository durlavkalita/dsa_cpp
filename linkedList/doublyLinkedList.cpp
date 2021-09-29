#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  Node* next;
  Node* prev;
};
struct Node* head;
struct Node* GetNewNode(int x) {
  struct Node* newNode = new Node();
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}
// Implementation //
void InsertAtHead(int x) {
  struct Node* newNode = GetNewNode(x);
  if(head == NULL) {
    head = newNode;
    return;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}
void Print() {
  struct Node* temp = head;
  cout<<"Forward: ";
  while (temp!=NULL)
  {
    cout<<temp->data;
    temp = temp->next;
  }
  cout<<"\n";
}
void ReversePrint() {
  struct Node* temp = head;
  if(temp == NULL) return;
  while(temp->next != NULL) {
    temp = temp->next;
  }
  cout<<"Reverse: ";
  while (temp!=NULL) 
  {
    cout<<temp->data;
    temp = temp->prev;
  } 
  cout<<"\n";
}

int main()
{
  head = NULL;
  InsertAtHead(2); Print(); ReversePrint();
  InsertAtHead(4); Print(); ReversePrint();
  InsertAtHead(6); Print(); ReversePrint();
  InsertAtHead(5); Print(); ReversePrint();
}