/* Delete a node whose address is given */

#include<cstdio>
#include<cassert>
#include<cstdlib>
#include<iostream>

using namespace std;


struct node 
{
  int data;
  struct node *next;
};


/* API assumes that if the node is the last node to be deleted, then it will make it a dummy node pointed by -1 in data field */

void deletenode(struct node *curnode)
{
  if(curnode == NULL)
  {
    return;
  }

  if(curnode->next == NULL)
  {
    //Make curnode Dummynode 
    curnode->data = -1;
    return;
  }
  
  
  curnode->data = curnode->next->data;

  //Now delete curnode->next

  struct node *deletenode = curnode->next;
  curnode->next = curnode->next->next;

  free(deletenode);

}

void printList(struct node *head)
{
 struct node *temp = head;
 while(temp != NULL)
 {
  printf("%d  ", temp->data);
  temp = temp->next;
}
}
void push(struct node** head_ref, int new_data)
{
   /* allocate node */
 struct node* new_node =
 (struct node*) malloc(sizeof(struct node));
 
   /* put in the data  */
 new_node->data  = new_data;
 
   /* link the old list off the new node */
 new_node->next = (*head_ref);
 
   /* move the head to point to the new node */
 (*head_ref)    = new_node;
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
  struct node* head = NULL;
  
    /* Use push() to construct below list
    1->12->1->4->1  */
  push(&head, 1);
  push(&head, 4);
  push(&head, 1);
  push(&head, 12);
  push(&head, 1);
  
  printf("Before deleting \n");
  printList(head);
  
    //Test case 1 
  deletenode(head);
  
  printf("\nAfter deleting \n");
  printList(head);
    //Test case 2
  deletenode(head->next->next);
  
  printf("\nAfter deleting \n");
  printList(head);
    //Test case 3
  deletenode(head->next->next);
  
  printf("\nAfter deleting \n");
  printList(head);
  getchar(); 
  return 0;
}

