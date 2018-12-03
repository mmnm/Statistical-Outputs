#include<iostream>
#include<vector>
#include<unordered_map>

/*


Assumptions: 1. Numbers can be on repeat
	     2. Fits in memory
	     3. Lists are not sorted


{1,7,2,5,3,7}
{2,7,7,5,7}



Apporoach: 1. Build hash freq of smaller list
	   2. Scan the other list and check if key exists in hash
	   3. Update hashfreq

*/

using namespace std;


class Test
{
	public:
	
	vector<int> intersectionLists(vector<int> list1, vector<int> list2)
	{
		vector<int> &vBuildHash = list2;
		vector<int> &vUse = list1;
		unordered_map<int, int> freqHash;
		vector<int> result;

		if(list1.size() >= list2.size())
		{
			vUse = list1;
			vBuildHash = list2;
		}
		else
		{
			vUse = list2;
			vBuildHash = list1;
		}

		 
		for(int i = 0; i < vBuildHash.size(); i++)
		{
			int curElem = vBuildHash[i];

			if(freqHash.find(curElem) != freqHash.end())
			{
				freqHash[curElem]++;
			}
			else 
			{
				freqHash[curElem] = 1;
			}
		}


		for(int i = 0; i < vUse.size(); i++)
		{
			int curElem = vUse[i];

			if(freqHash.find(curElem) != freqHash.end())
			{
				result.push_back(curElem);
				//Update hash
				freqHash[curElem]--;

				if(freqHash[curElem] <= 0)
				{
					freqHash.erase(curElem);
				}
			}
		}

		return result;

			


	}



};


void printVector(vector<int> test)
{

	for(int i = 0; i < test.size(); i++)
	{
		cout<<test[i]<<" ";
	}
	cout<<endl;	
	

}
int main()
{
	class Test A;
	//Test case 1
	vector<int> inp1 = {1,7,2,5,3,7};
	vector<int> inp2 = {2,7,7,5,7};
	printVector(A.intersectionLists(inp1, inp2));

	return 0;

}
