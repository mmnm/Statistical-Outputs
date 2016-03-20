#include<iostream>

using namespace std;



/* Implement stack , queue and queue using stacks

*/




struct stack
{
	int data;
	struct stack *next;
};


struct stack * newNode(int data)
{
	
	struct stack *temp = new stack();
	temp->data = data;
	temp->next = NULL;

	return temp;
}	

void stack_push(struct stack **head, int elem)
{

	struct stack *newElem = newNode(elem);

	//Push at the front

	newElem->next = *head;

	*head = newElem;
}

int stack_top(struct stack **head)
{
	if( (head == NULL) || (*head == NULL) )
	{
		return -1;
	}

	return (*head)->data;
}


void stack_pop(struct stack **head)
{

	if( (head == NULL) || (*head == NULL) )
	{
		return;
	}

	struct stack *temp = *head;

	*head = (*head)->next;

	delete(temp);
	
}




int main()
{

	struct stack *head = NULL;
	int choice;
	int elem;

	for(;;)
	{
		cout<<" 1 . Push in stack\n"
		      "2. Pop from stack\n"
		
			"3. Exit\n"<<endl;
		
		cin>>choice;
		
		switch(choice)
		{
		
			case 1: 
				cout<<"\nEnter element to push: ";
				cin>>elem;
				
				stack_push(&head, elem);
				break;

			case 2:

				cout<<"\nPopped elem: "<<stack_top(&head)<<endl;
				stack_pop(&head);
				break;
			
			case 3: 
				exit(1);
		
			default:
				cout<<"\nWe should not be here"<<endl;
				break;
		}


	}

	return 0;

}

				



	


