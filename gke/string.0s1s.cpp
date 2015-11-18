/*
Segregate 0s and 1s in an array

You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. Traverse array only once.

Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
Reverse of Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 
*/

#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

/*
i    0
j    0


*/
void segregate0s(int *arr, int len)
{
	if(arr == NULL)
		return;

	int j = 0;
	int count = 0;
	int i = 0;

	for(i = 0; i < len; i++)
	{
		int cur = arr[i];
		if(cur == 0)
		{
			count++;
		}
		else 
		{
			arr[j++] = arr[i];
		}
	}
	cout<<"Hey"<<count<<endl;
	for(int k = j; k < len; k++)
	{
		arr[k] = 0;
	}

	return;

}


int main()
{
	int arr[] = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
	cout<<"Original array is "<<arr<<endl;
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		cout<<" "<<arr[i];	
	}

	segregate0s(arr, sizeof(arr)/sizeof(int));
	cout<<"returned arr"<<endl;
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		cout<<" "<<arr[i];	
	}


	return 0;

}
