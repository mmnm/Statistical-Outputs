/*

Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Examples:

Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
|
|    |
|  | |
|__|_| 
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  See below diagram also.

Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
| 
|   || |
_|_||_||||||
Trap "1 unit" between first 1 and 2, "4 units" between
first 2 and 3 and "1 unit" between second last 1 and last 2 


*/

/*

steps: 1 compute the maxHeight for left and right sides from each array index
steps: 2 compute max water at each block -> min(lh, rh) - arr[cur]


*/

#include<iostream>
using namespace std;



int maxWater(int *arr, int len)
{
	if(arr == NULL)
	{
		return 0;
	}



	int leftMax[len];
	int rightMax[len];



//Pre calculate left and right 

	leftMax[0] = arr[0];

	for(int i = 1; i < len; i++)
	{
		leftMax[i] = max(leftMax[i - 1], arr[i]);
	}


	rightMax[len - 1] = arr[len - 1];

	for(int i = len - 2; i >= 0; i--)
	{
		rightMax[i] = max(rightMax[i + 1], arr[i]);
	}


	int water = 0;

//Calculate the water now

	for(int i = 0; i < len; i++)
	{
		water += (min(leftMax[i], rightMax[i]) - arr[i]);

	}

	return water;

}


// Driver program
int main()
{
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Maximum water that can be accumulated is "
	<< maxWater(arr, n);
	return 0;
}

























