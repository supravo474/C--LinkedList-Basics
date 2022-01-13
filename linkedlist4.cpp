#include <stdlib.h>

#include <iostream>
using namespace std;

// Create a node
struct Node {
  int data;
  struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
  // Allocate memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the data
  new_node->data = new_data;
  new_node->next = (*head_ref);

  // Move head to new node
  (*head_ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* prev_node, int new_data) {
  if (prev_node == NULL) {
  cout << "the given previous node cannot be NULL";
  return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Insert at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref; /* used in step 5*/

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

// Delete a node
void deleteNode(struct Node** head_ref, int key) {
    //head note
  struct Node *temp = *head_ref, *prev;
    //if head node is the key then delete it
  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node(here we are moving the temp value to previous value then we are deleting the temp )
  prev->next = temp->next;
    //Free memory or delete the node
  free(temp);
}

// Search a node
bool searchNode(struct Node** head_ref, int key) {
    //Declaring the head node
  struct Node* current = *head_ref;

    //Traversing until we reach the last node
  while (current != NULL) {
  if (current->data == key) return true;//If the current data is = to the key return true else return false
  current = current->next;
  }
  return false;
}

//Sort the node
void sortLinkedList(struct Node** head_ref) {
    //Declaring head,current and index node(for bubblesort)
  struct Node *current = *head_ref, *index = NULL;
  //For swapping(for bubblesort)
  int temp;

    //If no head then return
  if (head_ref == NULL) {
  return;
  }//Else keep traversing till last node
   else {
  while (current != NULL) {
    // index points to the node next to current
    index = current->next;//To not lose connection

    while (index != NULL) {
    if (current->data > index->data) {//If current node's data is greater than index's node data, swap the data between them  

      temp = current->data;
      current->data = index->data;
      index->data = temp;
    }
    index = index->next;//else keep traversing
    }
    current = current->next;// keep traversing because index is dependent on current
  }
  }
}
void printList(struct Node* node) {
  while (node != NULL) {
  cout << node->data << " "<<endl;
  node = node->next;
  }
}

int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  cout << "Linked list: ";
  printList(head);

 // cout << "\nAfter deleting an element: ";
  //deleteNode(&head, 4);
 // printList(head);

    //int man;
   // cout<<"Enter the number to search"<<endl;
   // cin>>man;
  //int item_to_find = man;
 // if (searchNode(&head, item_to_find)) {
  //cout << endl << item_to_find << " is found";
 // } else {
  //cout << endl << item_to_find << " is not found";
  //}

  sortLinkedList(&head);
  cout << "\nSorted List: ";
  printList(head);
}