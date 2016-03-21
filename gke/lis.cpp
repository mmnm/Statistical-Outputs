
/* Find LIS in an array */

#include<iostream>
using namespace std;


int lis(int *arr, int len)
{
	/*

	think
	10, 22, 9, 33, 21, 50, 41, 60

	e   e   e   e
	*/

	int max_len_seen = 0;
	int lis_arr[len];

	lis_arr[0] = 1;
	for(int i = 1; i < len; i++)
	{
		lis_arr[i] = -1;
	}

	for(int i = 1; i < len; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if((arr[j] < arr[i]) && lis_arr[j] + 1 > lis_arr[i])	
			{
				lis_arr[i] = lis_arr[j] + 1;
			}
		}

		if(max_len_seen < lis_arr[i])
		{
			max_len_seen = lis_arr[i];
		}
	}

	return max_len_seen;
				
}


/* Driver program to test above function */
int main()
{
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LIS is %d\n", lis( arr, n ) );
  return 0;
}
