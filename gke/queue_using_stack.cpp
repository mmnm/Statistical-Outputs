/* Implement queue using stack */


#include<iostream>
#include<stack>
using namespace std;

/* 

	<- 1 2 3 4 5 <-

  stack    -->    1 2 3 4 5 
           <--

the idea is to use two stacks

Keep pushing elements in s1 stack on enqueue operation
On a dequeue operation, return elements from s2 stack if it is non-empty. 
if s2 is empty then pop all elements from s1 and push to s2 and 
then return from s2 upon popping. 
If both s2 and s1 are empty then return null. The size of queue would be size 
of s1 + size of s2

*/



struct my_queue
{	
	std::stack<int> s1;
	std::stack<int> s2;
};


void queue_push(struct my_queue *q, int elem)
{
	if(q == NULL)
	{
		return;
	}

	q->s1.push(elem);

}

int queue_dequeue(struct my_queue *q)
{
	if(q == NULL)
	{
		return -1;
	}

	if(q->s2.empty())
	{
		//pop all elems from s1 and put it to s2
		while(!(q->s1.empty()))
		{
			int curElem = q->s1.top();
			q->s1.pop();
			q->s2.push(curElem);
		}
	}

	if(q->s2.empty())
	{
		return -1;
	}
	
	int ret_elem = q->s2.top();
	q->s2.pop();
	return ret_elem;

}



int main()
{
	int elem = 0;
	int choice = 0;

	struct my_queue myQ;

	for(;;)
	{
		cout<<"Enter choices:  1: Push to queue 2: Pop From queue"
			"3: Exit"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1: 
				cout<<"Enter elem" <<endl;
				cin>>elem;
				cout<<"Pushed in queue elem: "<<elem<<endl;
				queue_push(&myQ, elem);
				break;

			case 2: 				 
				cout<<"Popped elem is: "
				<<queue_dequeue(&myQ)<<endl;
				break;
			case 3: 
				exit(1);
			default:
				cout<<"Unsupported choice"<<endl;
				break;

		}





	}


}

		
			






	


