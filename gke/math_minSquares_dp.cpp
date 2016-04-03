

/* 
Minimum number of squares whose sum equals to given number n
*/

#include<iostream>
using namespace std;




int minSquares(int n)
{

	int dp_res[n + 1];


	//Fill for the base cases

	dp_res[0] = 0;
	dp_res[1] = 1;
	dp_res[2] = 2;
	dp_res[3] = 3;


	for(int i = 4; i <= n; i++)
	{
		dp_res[i] = i;

		//Now calculate for this one

		for(int j = 1; j <= i; j++)
		{
			int curRes = j * j;

			if(curRes == i)
			{
				dp_res[i] = 1;
				break;
			}
			else if(curRes > i)
			{
				dp_res[i] = min(dp_res[i], 1 + dp_res[i - (j - 1)*(j - 1)]);
				break;
			}
		}
	}

	return dp_res[n];

}

	
	
// Driver program
int main()
{
    cout << minSquares(6)<<endl;
    cout << minSquares(10)<<endl;
    cout << minSquares(100)<<endl;
    return 0;
}
