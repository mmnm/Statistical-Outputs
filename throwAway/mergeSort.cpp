#include<iostream>
#include<vector>
using namespace std;

/* 

Test case 1: 
{10,1,9,2,3,7,5,4,6,8} 
o/p : 1,2,3,4,5,6,7,8,9,10





*/


class Solution
{

	public:

	void combine(vector<int>& inp, int s1, int e1, int s2, int e2)
	{
	
		int start = s1;
	
		vector<int> comb;

		for(; s1 <= e1 || s2 <= e2; )
		{
			/*Both lists non empty yet*/
			if(s1 <= e1 && s2 <= e2)
			{
				if(inp[s1] < inp[s2])
				{
					comb.push_back(inp[s1++]);
				}
				else
				{
					comb.push_back(inp[s2++]);
				}
			}
			else if(s1 <= e1)
			{
				comb.push_back(inp[s1++]);
			}
			else if(s2 <= e2)
			{
				comb.push_back(inp[s2++]);
			}
		}

		for(int i = 0; i < comb.size(); i++)
		{
			inp[start++] = comb[i];
		}


	}

		
				
	
	void mergeSUtil(vector<int> & inp, int s, int e)
	{
		/* If only 1 elem*/
		if(s >= e)
		{
			return;
		}
		int mid = (s + e) / 2;

		mergeSUtil(inp, s, mid);
		mergeSUtil(inp, mid + 1, e);

		/* Merge sorted lists */

		combine(inp, s, mid, mid + 1, e);
	

	}


	void mergeS(vector<int> & inp)
	{
		mergeSUtil(inp, 0, inp.size() - 1);	

	}

	


};

void printV(vector<int> v)
{
	cout<<endl;
	
	for(int i = 0; i < v.size(); i++)
	{
		cout<<" "<<v[i];
	}
	cout<<endl;
}

int main()
{

	/*test case 1*/

	std::vector<int> test1 = {10,1,9,2,3,7,5,4,6,8};
	std::vector<int> test2 = {10,9,8,7,6,5,4,3,2,1};
	std::vector<int> test3 = {1,2,3,4,5,6,7,8,9,10};
	std::vector<int> test4 = {10};
	std::vector<int> test5 = {10,9};
	std::vector<int> test6 = {9,10};
	std::vector<int> test7 = {7,10,9};
	std::vector<int> test8 = {7,10,9,8};

	Solution A;


	cout<<"Orig: "<<endl;
	printV(test1);
	A.mergeS(test1);
	cout<<"Merged result: "<<endl;
	printV(test1);
	cout<<"************"<<endl;

	cout<<"Orig: "<<endl;
	printV(test2);
	A.mergeS(test2);
	cout<<"Merged result: "<<endl;
	printV(test2);
	cout<<"************"<<endl;

	cout<<"Orig: "<<endl;
	printV(test3);
	A.mergeS(test3);
	cout<<"Merged result: "<<endl;
	printV(test3);
	cout<<"************"<<endl;

	cout<<"Orig: "<<endl;
	printV(test4);
	A.mergeS(test4);
	cout<<"Merged result: "<<endl;
	printV(test4);
	cout<<"************"<<endl;

	cout<<"Orig: "<<endl;
	printV(test5);
	A.mergeS(test5);
	cout<<"Merged result: "<<endl;
	printV(test5);
	cout<<"************"<<endl;

	cout<<"Orig: "<<endl;
	printV(test6);
	A.mergeS(test6);
	cout<<"Merged result: "<<endl;
	printV(test6);
	cout<<"************"<<endl;

	cout<<"Orig: "<<endl;
	printV(test7);
	A.mergeS(test7);
	cout<<"Merged result: "<<endl;
	printV(test7);
	cout<<"************"<<endl;

	cout<<"Orig: "<<endl;
	printV(test8);
	A.mergeS(test8);
	cout<<"Merged result: "<<endl;
	printV(test8);
	cout<<"************"<<endl;

	return 0;
}
