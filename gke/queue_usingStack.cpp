/* Implement queue using stack */

/* 

Use two stacks 

s1      s2

queue_push --> add to s1

queue_pop --> if s2 is empty -> pop all elems from s1 and put in s2, return top
if s2 is not empty ----> return top elem and pop


*/

#include<iostream>
#include<stack>


	using namespace std;



class IntQueue_usingStack
{
private:
	std::stack<int> s1;
	std::stack<int> s2;

public:
	void queue_enqueue(int data);
	int queue_dequeue(void);

};

void IntQueue_usingStack::queue_enqueue(int data)
{
	s1.push(data);
}

int IntQueue_usingStack::queue_dequeue()
{
	int elem = -1;
	if(!(s2.empty()))
	{
		elem = s2.top();
		s2.pop();
	}
	else
	{
		while(!(s1.empty()))
		{
			int cur = s1.top();
			s1.pop();
			s2.push(cur);
		}
		if(s2.empty())
		{
			return elem;
		}
		elem = s2.top();
		s2.pop();
	}

	return elem;
}


/* Driver function to test above functions */
int main()
{
/* Create a queue with items 1 2 3*/

	IntQueue_usingStack q1;

	q1.queue_enqueue(1);
	q1.queue_enqueue(2);
	q1.queue_enqueue(3);

	cout<<"\n"<<q1.queue_dequeue();
	q1.queue_enqueue(4);
	q1.queue_enqueue(5);
	cout<<"\n"<<q1.queue_dequeue();
	cout<<"\n"<<q1.queue_dequeue();
	cout<<"\n"<<q1.queue_dequeue();
	q1.queue_enqueue(6);
	cout<<"\n"<<q1.queue_dequeue();
	cout<<"\n"<<q1.queue_dequeue();
	cout<<"\n"<<q1.queue_dequeue();
	q1.queue_enqueue(7);
	cout<<"\n"<<q1.queue_dequeue()<<endl;

	return 0;

}







