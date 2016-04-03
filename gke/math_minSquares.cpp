


/* 
Minimum number of squares whose sum equals to given number n
*/

#include<iostream>
using namespace std;



int minSquares(int n)
{

	if(n <= 0) 
	{
		return 0;
	}


	if(n == 1)	
	{
		return 1;
	}

	int count = 0;
	for(int i = 1; i <= n; i++)
	{
		int curMul = i *i;
		if(curMul == n)
		{
			count++;
			return count;
		}
		else if(curMul > n)
		{
			//Recurse to the lower values
			count++;
			int lower = n - (i - 1)*(i - 1);
			return count + minSquares(lower);
		}

	}	

	return count;

}


// Driver program
int main()
{
    cout << minSquares(6)<<endl;
    cout << minSquares(10)<<endl;
    cout << minSquares(100)<<endl;
    return 0;
}
