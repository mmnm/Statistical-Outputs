#include<iostream>
#include<vector>


using namespace std;


/*

Input 1: {1,0,1,1,0,0,1,1,0,1};
Output:  {1,1,1,1,1,1,0.0.0.0};

*/

class Solution {


public:

	void moveZero(vector<int>& inp)
	{	

		/*
			Scan left to right and move 1s to left if 0 is
			 encountered

		*/

		int j = 0;
		for(int i = 0; i < inp.size(); i++)
		{
			if(inp[i] == 1)
			{
				inp[j++] = 1;
			}

		}


		cout<<"j val: "<<j<<endl;
		for(; j < inp.size(); j++)
		{
			inp[j] = 0;
		}


	}





};


void printV(vector<int> inp)
{
	cout<<endl;

	for(int i = 0; i < inp.size(); i++)
	{
		cout<<" "<<inp[i];
	}
	cout<<endl;
}



int main()
{
	Solution A;

	vector<int> test1 = {1,0,1,1,0,0,1,1,0,1};
	cout<<"\nTest case 1: "<<endl;
	printV(test1);
	A.moveZero(test1);
	cout<<"\nAfter moveZeros: "<<endl;
	printV(test1);

	vector<int> test2 = {1,1,1,1,1,1,1};
	cout<<"\nTest case 2: "<<endl;
	printV(test2);
	A.moveZero(test1);
	cout<<"\nAfter moveZeros: "<<endl;
	printV(test2);

	vector<int> test3 = {0,0,0,0,0,0,0,0,0,0};
	cout<<"\nTest case 3: "<<endl;
	printV(test3);
	A.moveZero(test3);
	cout<<"\nAfter moveZeros: "<<endl;
	printV(test3);

	vector<int> test4 = {1,0,1,0};
	cout<<"\nTest case 4: "<<endl;
	printV(test4);
	A.moveZero(test4);
	cout<<"\nAfter moveZeros: "<<endl;
	printV(test4);

	vector<int> test5 = {1,1,1,0,0};
	cout<<"\nTest case 5: "<<endl;
	printV(test5);
	A.moveZero(test5);
	cout<<"\nAfter moveZeros: "<<endl;
	printV(test5);

	return 0;

}






