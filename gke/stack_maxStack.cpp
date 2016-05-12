/* Design/extend a  method to return max element in a stack class usage */


#include<iostream>
#include<stack>

using namespace std;


std::stack<int> maxElemStack;


int stack_max(std::stack<int> *s1)
{
	if(s1 == NULL)
	{
		return -1;
	}

	if(s1->empty())
	{
		return -1;
	}

	if(maxElemStack.empty() && !(s1->empty()))
	{
		cout<<"Debug this error for no max elem"<<endl;
		return -1;
	}
	return maxElemStack.top();
}


void push_stack(std::stack<int> *s1, int elem)
{
	if(s1 == NULL)
	{
		return;
	}

	s1->push(elem);

		
	if(maxElemStack.empty() || maxElemStack.top() < elem)
	{
		maxElemStack.push(elem);
	}
	
	cout<<"Current max at this step in stack is: "<<stack_max(s1)<<endl;

}


int pop_stack(std::stack<int> *s1)
{
	if(s1->empty())
	{
		return -1;
	}
	int topElem = s1->top();
	s1->pop();	

	if(maxElemStack.empty())
	{
		return topElem;
	}

	if(maxElemStack.top() == topElem)
	{
		maxElemStack.pop();
	}

	cout<<"\nCurrent max at this step in stack is: "<<stack_max(s1)<<endl;
	return topElem;
}


int main()
{
	

	//Test case

	std::stack<int> s;

	//Test case 1: ascending order
	push_stack(&s, 1);
	push_stack(&s, 2);
	push_stack(&s, 3);
	push_stack(&s, 4);
	push_stack(&s, 5);

	cout<<"Popped elem from stack: "<<pop_stack(&s)<<endl;
	cout<<"Popped elem from stack: "<<pop_stack(&s)<<endl;
	cout<<"Popped elem from stack: "<<pop_stack(&s)<<endl;
	cout<<"Popped elem from stack: "<<pop_stack(&s)<<endl;
	cout<<"Popped elem from stack: "<<pop_stack(&s)<<endl;
	cout<<"Popped elem from stack: "<<pop_stack(&s)<<endl;
	cout<<"Popped elem from stack: "<<pop_stack(&s)<<endl;
	
	
		


	return 0;


}


	

	
	

	




