#include<bits/stdc++.h>

using namespace std;

// creating a node
struct Node {
  int data;
  Node* next;
};

void insertAtBeginning(struct Node** head_ref, int data){
  Node* temp = new Node();
  temp->data = data;
  temp->next = (*head_ref);

  (*head_ref) = temp;
}

void insertAtN(struct Node** head_ref, int pos, int data){
  Node* temp1 = new Node();
  temp1->data = data;
  temp1->next = NULL;
  
  if (pos == 1)
  {
    temp1->next = *head_ref;
    *head_ref = temp1;
    return;
  }

  Node* temp2 = *head_ref;
  for (int i = 0; i < pos-2; i++)
  {
    temp2 = temp2->next; 
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
  
}

void insertAtEnd(struct Node** head_ref, int data){
  Node* temp = new Node();
  temp->data = data;
  temp->next = NULL;

  if (*head_ref == NULL) 
  {
    *head_ref = temp;
    return;
  }
  Node* last = *head_ref;
  while (last->next != NULL)
  {
    last = last->next;
  }
  last->next = temp;
  return;
}

void deleteNodeByPos(struct Node** head_ref, int pos) {
  Node* temp1 = *head_ref;
  if(pos == 1) {
    *head_ref = temp1->next;
    delete temp1;
    return;
  }
  for (int i = 0; i < pos-2; i++)
  {
    temp1 = temp1->next; // find pos-1 node
  }
  Node* temp2 = temp1->next; // pos node
  temp1->next = temp2->next; // pos+1 node
  delete temp2;
}

void deleteNodeByData(struct Node** head_ref, int data) {
  Node* temp1 = *head_ref;
  if (temp1->data == data) 
  {
    *head_ref = temp1->next;
    delete temp1;
    return; 
  }
  Node* temp2 = temp1->next;
  while (temp2->data != data)
  {
    temp1 = temp2; // prev node
    temp2 = temp2->next; // delete this node
  }
  temp1->next = temp2->next; // pos+1 node
  delete temp2;
}

int searchNode(struct Node** head_ref, int data) {
  Node* current = *head_ref;
  int i = 1;
  while (current != NULL)
  {
    if (current->data == data) 
    {
      return i;
    }
    current = current->next;
    i++;
  }
  return -1;
}

void sortLinkedList(struct Node** head_ref){
  Node* current = *head_ref;
  Node* index = NULL;
  int temp;

  if (*head_ref == NULL)
  {
    return;
  } else {
    while (current != NULL)
    {
      index = current->next;

      while (index != NULL)
      {
        if (current->data > index->data)
        {
          temp = current->data;
          current->data = index->data;
          index->data = temp;
        }
        index = index->next;
      }
      current = current->next;
    }
  }
  
}

void reverseList(struct Node** head_ref) {
  struct Node *current, *next, *prev;

  current = *head_ref;
  prev = NULL;
  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head_ref = prev;
}

// void reverseListWithRecursion(struct Node* head_ref) {
//   struct Node* current;
//   current = head_ref;
//   if (current->next == NULL)
//   {
//     return;
//   }
//   reverseListWithRecursion(current->next);
//   Node* temp = current->next;
//   temp->next = current;
//   current->next = NULL;
// }

void printList(struct Node* node) {
  while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
  }
}

void printListWithRecursion(struct Node* node) {
  if (node == NULL) return;
  cout<< node->data << " ";
  printListWithRecursion(node->next);
}

void reversePrintListWithRecursion(struct Node* node) {
  if (node == NULL) return;
  reversePrintListWithRecursion(node->next);
  cout<< node->data << " ";
}

int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAtN(&head, 2, 5);

  cout << "Linked list: ";
  printList(head);

  cout<< "\nList print with recursion: ";
  printListWithRecursion(head);

  cout<< "\nReverse List print with recursion: ";
  reversePrintListWithRecursion(head);

  cout<< "\nReversed list: ";
  reverseList(&head);
  printList(head);

  // cout<< "\nReversed list with recursion: ";
  // reverseListWithRecursion(head);
  // printList(head);

  cout << "\nAfter deleting an element by position 3: ";
  deleteNodeByPos(&head, 3);
  printList(head);
  
  cout << "\nAfter deleting an element by data 1: ";
  deleteNodeByData(&head, 1);
  printList(head);

  int data = 5;
  if (searchNode(&head, data) == -1) {
  cout << endl << data << " is not found";
  } else {
  cout << endl << data << " is found at position " <<searchNode(&head, data);
  }

  sortLinkedList(&head);
  cout << "\nSorted List: ";
  printList(head);
}