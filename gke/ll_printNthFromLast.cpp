


// Simple C program to find n'th node from end
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

/* Link list node */
struct node
{
	int data;
	struct node* next;
};





void printNthFromLast(struct node* head, int n)
{

	cout<<"\nPrinting "<<n<<" element from back: ";
	if(head == NULL)
	{
		return;
	}

	if(n < 1)
	{
		return;
	}


	struct node *cur = head;
	
	n++;
	struct node *behind = cur;
	while(cur != NULL)
	{
		cur = cur->next;
		n--;

		if(n <= 0)
		{
			behind = behind->next;
		}	
	}	
	
	if(n > 1)
	{
		cout<<"No valid print"<<endl;
		return;
	}

	if(behind)
		cout<<"\n"<<behind->data<<endl;

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
	
  // create linked 35->15->4->20
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);
	
	printNthFromLast(head, 5);
	printNthFromLast(head, 1);
	printNthFromLast(head, 2);
	printNthFromLast(head, 3);
	printNthFromLast(head, 4);
	return 0; 
}
