/* Implement stack using queue*/

#include<queue>
#include<iostream>
using namespace std;


/* 

Idea: How to implement stack using queue 

stack operations: top, push, pop, size

stack e.g.,
                  54321


queue
                 12345
 


queue           

Logic: Push all elements in queue one by one on a push call, at each pop call 


dequeue an element n times and enque n - 1 times again, return the nth enque



*/




struct my_stack
{
	std::queue<int> myQ;

};


void push_stack(int elem, struct my_stack *st)
{
	if(st == NULL)
	{
		return;
	}

	st->myQ.push(elem);

}	

int pop_stack(struct my_stack *st)
{
	if(st == NULL)
	{
		return -1;
	}

	int curSize = st->myQ.size();

	if(curSize == 0)
	{
		return -1;
	}

	//dequeue curSize times and push back curSize -1 elems
	//Return curSize'th elem

	for(int i = 0; i < curSize - 1; i++)
	{
		int curElem = st->myQ.front();
		st->myQ.pop();
		st->myQ.push(curElem);	

	}

	int ret_elem = st->myQ.front();
	st->myQ.pop();

	return ret_elem;
	
}	




		

int main()
{
	int elem = 0;
	int choice = 0;

	struct my_stack myS;

	for(;;)
	{
		cout<<"Enter choices:  1: Push to stack 2: Pop From stack"
			"3: Exit"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1: 
				cout<<"Enter elem" <<endl;
				cin>>elem;
				cout<<"Pushed in stack elem: "<<elem<<endl;
				push_stack(elem, &myS);
				break;

			case 2: 				 
				cout<<"Popped elem is: "<<pop_stack(&myS)<<endl;
				break;
			case 3: 
				exit(1);
			default:
				cout<<"Unsupported choice"<<endl;
				break;

		}





	}


}




















