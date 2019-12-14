#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

/*

	partition 

	{4, 6, 8, 1, 7, 2, 3, 9, 5, 10}




*/



class Solution {


		public:

			void randomize(vector<int>& inp, int s, int e)
			{
			
				int limit = e - s + 1;
				int rand_index = rand() % limit + s;
		
				int temp = inp[s];
				inp[s] = inp[rand_index];
				inp[rand_index] = temp;
				
			}
			

			int partition(vector<int>& inp, int s, int e)
			{


				if( s >= e)
				{
					//cout<<"Returning: "<<s<<endl;
					return -1;
				}
	
				//Randomize part elem 
				randomize(inp, s, e);

				int part_elem = inp[s];
				int part_index = s;
				int i = s + 1;

				for(; i <= e; i++)
				{
					if(inp[i] < part_elem)
					{
						int temp = inp[s + 1];
						inp[s + 1] = inp[i];
						inp[i] = temp;
						s++;
					}	
				
	
				}

				//Last swap
				inp[part_index] = inp[s];
				inp[s] = part_elem;

				return s;
				
			

			}




			void qSrtUtil(vector<int>& inp, int s, int e)
			{
				
				
				int part_r = partition(inp, s, e);

				//cout<<"part_r: "<<part_r<<endl;

				if(part_r == -1)
				{
					return;
				}

				qSrtUtil(inp, s, part_r - 1);
				qSrtUtil(inp, part_r + 1, e);
			

			}

			void qSrt(vector<int>& inp)
			{
				if(inp.size() <= 1)
				{
					return;

				}

				qSrtUtil(inp, 0, inp.size() - 1);


			}





};


void printV(vector<int> elem)
{
	cout<<endl;

	for(int i = 0; i < elem.size(); i++)
	{
		cout<<" "<<elem[i];
	}
	
	cout<<endl;

}


int main()
{

	Solution A;


	//Test 1
	vector<int> test1 = {4, 6, 8, 1, 7, 2, 3, 9, 5, 10};
	cout<<"Test case 1: "<<endl;
	printV(test1);
	cout<<"After qSrt: "<<endl;
	A.qSrt(test1);
	printV(test1);
	


	//Test 2
	vector<int> test2 = {5,4};
	cout<<"Test case 2: "<<endl;
	printV(test2);
	cout<<"After qSrt: "<<endl;
	A.qSrt(test2);
	printV(test2);
	

	
	//Test 3
	vector<int> test3 = {1,2,3,4,5,6,7,8,9,10};
	cout<<"Test case 3: "<<endl;
	printV(test3);
	cout<<"After qSrt: "<<endl;
	A.qSrt(test3);
	printV(test3);
	


	//Test 4
	vector<int> test4 = {10,9,8,7,6,5,4,3,2,1};
	cout<<"Test case 4: "<<endl;
	printV(test4);
	cout<<"After qSrt: "<<endl;
	A.qSrt(test4);
	printV(test4);
	
	//Test 5
	vector<int> test5 = {3,1,2};
	cout<<"Test case 5: "<<endl;
	printV(test5);
	cout<<"After qSrt: "<<endl;
	A.qSrt(test5);
	printV(test5);
	
	//Test 6
	vector<int> test6 = {3,2,1};
	cout<<"Test case 6: "<<endl;
	printV(test6);
	cout<<"After qSrt: "<<endl;
	A.qSrt(test6);
	printV(test6);
	

	return 0;
}

