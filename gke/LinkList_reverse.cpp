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


void reverse(struct node **head)
{
  if(head == NULL || *head == NULL)
  {
    return;
  }

  struct node *temp = *head;
  struct node *prev = NULL;

  while(temp != NULL)
  {
    struct node *cur = temp;
    temp = temp->next;
    cur->next = prev;
    prev = cur;
  }
  *head = prev;
}



/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
     
     printList(head);    
     reverse(&head);                      
     printf("\n Reversed Linked list \n");
     printList(head);    
  
     /* Test case 2 */

    cout<<"\nTest case 2"<<endl;
     struct node* head1 = NULL;
     push(&head1, 20);
     printList(head1);    
     printf("\n Reversed Linked list \n");
     printList(head1);    

     getchar();
}
