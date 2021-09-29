// reverse a linked list

#include<bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* next;
};

void Reverse(Node** head_ref) {
  struct Node* temp;
  temp = *head_ref;

  if(temp == NULL) return;

  stack<struct Node*> S;

  while(temp->next!=NULL) { // push linked list elements into stack S
    S.push(temp);
    temp = temp->next;
  }
  S.push(temp); // push the last element into stack
  *head_ref = temp;
  while (!S.empty()){ // while stack not empty
    temp->next = S.top(); // set next node value from top of stack and pop it.
    temp = temp->next;
    S.pop();
  }
  temp->next = NULL;
}

void insert(struct Node** head_ref, int data){
  Node* temp = new Node();
  temp->data = data;
  temp->next = (*head_ref);

  (*head_ref) = temp;
}

void printList(struct Node* node) {
  while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
  }
}

int main() 
{
  struct Node* head = NULL;

  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 4);
  insert(&head, 5);

  cout << "Linked list: ";
  printList(head);

  Reverse(&head);
  cout<< "\nReversed List: ";
  printList(head);

  return 0;
}