/* Max contiguous sum */

#include<iostream>

using namespace std;



int maxSubArraySum(int *arr, int len)
{
	int max_ending_here = 0;
	int max_sum = INT_MIN;


	for(int i = 0; i < len; i++)
	{
		int cur = arr[i];
		max_ending_here = max(cur, max_ending_here + cur);

		max_sum = max(max_sum, max_ending_here);
	}

	return max_sum;
}
	

/*


	Walk through example run

	{-2,    -3,    4,    -1,    -2,    1,    5,   -3};
         
                        
CUR	                                          7


MAX      7






*/


	

/* Driver program to test maxSubArraySum */
int main()
{
int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
int n = sizeof(a)/sizeof(a[0]);
int max_sum = maxSubArraySum(a, n);
cout << "Maximum contiguous sum is " << max_sum;
return 0;

}
