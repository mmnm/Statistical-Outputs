/*
Dynamic Programming | Set 3 (Longest Increasing Subsequence)
We have discussed Overlapping Subproblems and Optimal Substructure properties in Set 1 and Set 2 respectively.

Let us discuss Longest Increasing Subsequence (LIS) problem as an example problem that can be solved using Dynamic Programming.
The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.

*/



#include<iostream>

using namespace std;


int max_increasing_sum(int *arr, int len)
{

	if(arr == NULL)
	{
		return 0;
	}

/* keep track of loc_sum seen built form increasing seq and max_sum; return max_sum */

	int loc_sum = 0;
	int max_sum = 0;
	int lis_sum[len];

	for(int i = 0; i < len; i++)
	{
		lis_sum[i] = 0;
	}

	max_sum = lis_sum[0] = arr[0];

	for(int i = 1; i < len; i++)
	{
		int loc_sum = arr[i];

		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[j] < arr[i])
			{
				if((lis_sum[j] + arr[i]) > loc_sum)
				{
					loc_sum = lis_sum[j] + arr[i];
				}
			}
		}

		lis_sum[i] = loc_sum;
		if(max_sum < lis_sum[i])
		{
			max_sum = lis_sum[i];
		}
	}

	return max_sum;

}


int lis(int *arr, int len)
{
	if(arr == NULL)
	{
		return 0;
	}

	int lis_arr[len];


	for(int i = 0; i < len; i++)
	{
		lis_arr[i] = 1;
	}

	int max_seq_seen = 0;


	for(int i = 1; i < len; i++)
	{
		int loc_seq = 1;	
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[j] < arr[i])
			{
				if((lis_arr[j] + 1) > loc_seq)
				{
					loc_seq = lis_arr[j] + 1;

				}
			}
		}

		lis_arr[i] = loc_seq;
		if(max_seq_seen < loc_seq)
		{
			max_seq_seen = loc_seq;
		}
	}

	return max_seq_seen;
}


/* Driver program to test above function */
int main()
{

	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Length of lis is %d\n",
		lis( arr, n ));

	int arr1[] = {1, 101, 2, 3, 100, 4, 5};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	printf("Sum of maximum sum increasing subsequence is %d\n",
		max_increasing_sum( arr1, n1 ) );


//{3, 4, 5, 10}, then output should be 22 
	int arr2[] = {3,4,5,10};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	printf("\nSum of maximum sum increasing subsequence is %d\n",
		max_increasing_sum( arr2, n2 ) );




//if the input array is {10, 5, 4, 3}, then output should be 10
	int arr3[] = {10,5,4,3};
	int n3 = sizeof(arr3)/sizeof(arr3[0]);
	printf("\nSum of maximum sum increasing subsequence is %d\n",
		max_increasing_sum( arr3, n3 ) );

	return 0;
}		
