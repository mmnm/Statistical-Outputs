#include<iostream>
#include<vector>

using namespace std;


class Solution
{

public: 
vector<int> maxset(vector<int> &A);
};


vector<int> Solution::maxset(vector<int> &A) {
    
//Have a cur_sum and if elem > 0, then add elem to cur_sum 
//If elem < 0 or if all elems are processed, then update max


vector<int> res; 

long long int max_sum = 0;
int max_si = 0; 
int max_se = -1; 
long long int cur_sum = 0; 
int cur_si = 0; 
int cur_se = -1; 

for(int cur_se = 0 ; cur_se < A.size(); cur_se++)
{
    int curElem = A[cur_se]; 
    
    if(curElem >= 0)
    {
        //Update cur_sum 
        cur_sum += curElem; 
        
        if( ((max_sum == cur_sum) && ((max_se - max_si) < (cur_se - cur_si)))
            || (max_sum < cur_sum) )
        {
            //Update max
            max_sum = cur_sum; 
            max_se = cur_se; 
            max_si = cur_si; 
        }
        
    }
    else
    {
        //Reset cur_sum 
        cur_si = cur_se + 1;
        cur_sum = 0;
    }
    
}

for(int i = max_si; i <= max_se; i++)
{
    res.push_back(A[i]);
}
  
    
    return res;
    
    
}



void printV(vector<int> res)
{
	cout<<endl;
	for(int i = 0; i < res.size(); i++)
	{
		cout<<" " <<res[i];	
	}
	cout<<endl;
}

int main()
{
	vector<int> elem = {1, 2, 5, -7, 2, 5 };
	Solution A; 

	vector<int> res; 

	res = A.maxset(elem);

	printV(res);

	return 0;
}
