#include<iostream>

using namespace std;



/* Implement stack , queue and queue using stacks

*/




struct stack
{
	int data;
	struct stack *next;
};

struct queue
{
	struct stack *s1 = NULL;
	struct stack *s2 = NULL;
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


void queue_push(struct queue **head, int elem)
{
	//The element needs to be always inserted in s1.

	stack_push(&((*head)->s1), elem);
} 

int queue_dequeue(struct queue **head)
{
	//If s2 is empty then Push all elements from s1 to s2 and pop from s2
	if(stack_top( &(*head)->s2 ) == -1)
	{
		while( stack_top( &(*head)->s1 ) != -1)
		{
			int cur = stack_top( &(*head)->s1 );
			stack_pop( &(*head)->s1 );
			stack_push( &(*head)->s2, cur );
		}
	}

	//Now pop the element from s2 and return

	int retElem = stack_top( &(*head)->s2 );
	stack_pop( &(*head)->s2 );

	return retElem;
}







int main()
{

	struct queue *head = new queue();
	int choice;
	int elem;

	for(;;)
	{
		cout<<" 1 . Push in queue\n"
		      "2. Pop from queue\n"
		
			"3. Exit\n"<<endl;
		
		cin>>choice;
		
		switch(choice)
		{
		
			case 1: 
				cout<<"\nEnter element to push: ";
				cin>>elem;
				
				queue_push(&head, elem);
				break;

			case 2:

				cout<<"\nPopped elem: "<<queue_dequeue(&head)<<endl;
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

				



	

