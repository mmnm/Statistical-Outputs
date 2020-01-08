#include<iostream>
#include<vector>
using namespace std;


/* 

Example 1: 

Inp:
{1,0,1,1,0,1,1,0}


o/p: {1,1,1,1,1,0,0,0}}



Soln 1: 

Count nos of 1 andf reconstruct. 2 pass solution O(N)


Soln 2: 
Shift/copy 1s from the start and after the loop is completed, then copy 0s
, 1 pass O(N)

*/



class Solution
{

	public: 


/*



{1,1,1,1,1,0,0,0}
           i
               j
{1,0,1,1,0,1,1,0}

*/

	void moveZeros(vector<int> & inp)
	{
		int i = 0;
		
		for(int j = 0; j < inp.size(); j++)
		{
			if(inp[j] == 1)
			{
				inp[i++] = 1;
			}
		}

		for(; i < inp.size(); i++)
		{
			inp[i] = 0;
		}
	}

};


void printV(vector<int> inp)
{
	cout<<endl;

	for(int i = 0; i < inp.size(); i++)
	{
		cout<<" " <<inp[i];
	}

	cout<<endl;
}


int main()
{
	Solution A;


	//Test case 1

	vector<int> test1 = {1,0,1,1,0,1,1,0};
	cout<< "Input 1: "<<endl;
	printV(test1);
	cout<<"MoveZeros output: "<<endl;
	A.moveZeros(test1);
	printV(test1);
	
	//Test case 2

	vector<int> test2 = {1,1,1,1,1,1};
	cout<< "Input 2: "<<endl;
	printV(test2);
	cout<<"MoveZeros output: "<<endl;
	A.moveZeros(test2);
	printV(test2);
	
	//Test case 3

	vector<int> test3 = {0,0,0};
	cout<< "Input 3: "<<endl;
	printV(test3);
	cout<<"MoveZeros output: "<<endl;
	A.moveZeros(test3);
	printV(test3);
	
	//Test case 4

	vector<int> test4 = {0,0,0,0,0,1,1,1};
	cout<< "Input 4: "<<endl;
	printV(test4);
	cout<<"MoveZeros output: "<<endl;
	A.moveZeros(test4);
	printV(test4);
	
	//Test case 5

	vector<int> test5 = {1,0,1,0,1,0,1,0,1};
	cout<< "Input 5: "<<endl;
	printV(test5);
	cout<<"MoveZeros output: "<<endl;
	A.moveZeros(test5);
	printV(test5);
	
	//Test case 6

	vector<int> test6 = {1,1,1,1,1,1,1,0,0};
	cout<< "Input 6: "<<endl;
	printV(test6);
	cout<<"MoveZeros output: "<<endl;
	A.moveZeros(test6);
	printV(test6);
	
	//Test case 7

	vector<int> test7 = {0,1,1,1,1,1};
	cout<< "Input 7: "<<endl;
	printV(test7);
	cout<<"MoveZeros output: "<<endl;
	A.moveZeros(test7);
	printV(test7);
	
	return 0;

}
