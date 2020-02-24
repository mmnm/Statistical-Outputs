#include<iostream>
#include<vector>


using namespace std;

/* 

1,2, 4,3, 5,1

O/P: 1,1, 4,4,4,5, invalid, invalid


2,1,3,0, 4, -1, 5,1, 6
O/P : 2,5,invalid, invalid, invalid



 
*/



struct Result
{
	bool isValid;
	int res;
};


class Iter 
{
	
	private:
	
	vector<int> inp;
	int curPos = 0;
 


	public:

		Iter(vector<int> num) 
		{
			inp = num;
		}

		struct Result nextIter()
		{
			
			Result curRes;
			curRes.isValid = false;
			curRes.res = 0;
			
			
			if(inp.size() == 0 || curPos + 1 >= inp.size())
			{
				return curRes;
			}
			
			while(inp[curPos + 1] <= 0)
			{
				//Skip to next one

				curPos += 2;
				
				if(curPos + 1 >= inp.size())
				{
					return curRes;
				}
			}

			//Valid entry found
			curRes.isValid = true;
			curRes.res = inp[curPos];
			inp[curPos + 1]--;
			
			return curRes;

		}


};


int main()
{


	Iter test1({1,2, 4,3, 5,1});
	cout<<endl;
	for(int i = 0; i < 10; i++)
	{
		struct Result curR = test1.nextIter();
		if(curR.isValid == false)
		{
			cout<<" Invalid";
		}
		else 
		{
			cout<<" "<<curR.res;
		}

			
	}
	cout<<endl;

	Iter test2({1});
	cout<<endl;
	for(int i = 0; i < 10; i++)
	{
		struct Result curR = test2.nextIter();
		if(curR.isValid == false)
		{
			cout<<" Invalid";
		}
		else 
		{
			cout<<" "<<curR.res;
		}

			
	}
	cout<<endl;
	

	Iter test3({2,1,3,0, 4, -1, 5,1, 6});
	cout<<endl;
	for(int i = 0; i < 10; i++)
	{
		struct Result curR = test3.nextIter();
		if(curR.isValid == false)
		{
			cout<<" Invalid";
		}
		else 
		{
			cout<<" "<<curR.res;
		}

			
	}
	cout<<endl;

	return 0;
}

