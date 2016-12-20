/* 
Move all zeroes to end of array
Given an array of random numbers, Push all the zero’s of a given array to the end of the array. For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}
it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}.


{1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}
                      i
                               j
 
1   9  8  4  2  7  6  


*/
#include<iostream>
using namespace std;



void moveAllZeroToEnd(int *arr, int len)
{
	if(arr == NULL || len <= 1)
	{
		return;
	}

	int i = 0, j = 0;
	int count = 0;

	for(; j < len; j++)
	{
		int curElem = arr[j];
		
		if(curElem == 0)
		{
			continue;
		}
		else 
		{
			if(i == j) 
			{
				i++;
				continue;
			}
			else 
			{
				arr[i++] = curElem;
			}
		}
	}
		
	for(; i < len; i++)
	{
		arr[i] = 0;
	}

}

void printArray(int *arr, int len)
{
	cout<<"Array conetents:"<<endl;
	for(int i = 0; i < len; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}



int main()
{
	int array1[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
	cout<<"Original  array ";
	printArray(array1, sizeof(array1)/sizeof(array1[0]));
	
	moveAllZeroToEnd(array1, sizeof(array1)/sizeof(array1[0]));

	cout<<"Modified array ";
	printArray(array1, sizeof(array1)/sizeof(array1[0]));

	return 0;
}

	
			
		

	










