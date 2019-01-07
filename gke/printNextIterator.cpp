#include<iostream>
#include<vector>
#include<cstdlib>


using namespace std;


/* 
Example 1

12 1 9 2 7 3

Calling nextIter repeatedly prints below

-> 12 9 9 7 7 7 invalid invalid ....

Example 2

12 1 9 0 7 2 3 0 6 0 8 1

-> 12 7 7 8 invalid invalid ...

Example 3

12 1 3 0 4 0 5 0 

-> 12 invalid invalid ....


*/

struct result
{
	int data;
	bool isValid;
};


class IterData
{

	private:
	vector<int> elements;
	int pos;

	public:
	IterData(vector<int> vData) { elements = vData;}


	
	struct result * getNextIter()
	{
		struct result *res = new result();
		res->isValid = false;
		res->data = 0;


		//Iterate deeper till one valid print Entry is found 
		//or end is reached
	
		while((pos + 1 < elements.size()) && elements[pos + 1] <= 0)
		{
			pos += 2;
		}

		
		if(pos + 1 >= elements.size())
		{
			return res;
		}
		
		//Valid print entry found

		res->data = elements[pos];
		elements[pos + 1]--;
		
		res->isValid = true;

		return res;

		

	}

      	void printAllData()
	{
		struct result *temp = getNextIter();
	
			
		while(temp->isValid)
		{
			cout<<" "<<temp->data;
			temp = getNextIter();
		}

		if(temp->isValid == false)
		{
			cout<<" "<<"Invalid..."<<endl;

		}	

	
	}

};	


int main()
{
	cout<<"\nTest case 1: Must print 12, 9, 9, 7,7,7,invalid..."<<endl;
	vector<int> test1 = {12, 1, 9, 2, 7, 3};
	IterData A(test1);
	A.printAllData();

	cout<<"\nTest case 2: Must print 12 7 7 8 invalid invalid ..."<<endl;
	vector<int> test2 = {12,1,9,0,7,2,3,0,6,0,8,1};
	IterData B(test2);
	B.printAllData();
	
	cout<<"\nTest case 3: Must print 12 invalid invalid ...."<<endl;
	vector<int> test3= {12,1,3,0,4,0,5,0};
	IterData C(test3);
	C.printAllData();
	return 0;
}
	
