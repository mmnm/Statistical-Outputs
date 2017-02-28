#include<iostream>

using namespace std;



/* 

Put all zero's to the end of array in-place

E.g, 101011011   -> 111111000

*/


void put_zero_end(int *arr, int len)
{
	if(arr == NULL || len <= 1)
	{
		return;
	}

	int i = 0;
	int j = 0;
	
	for(; j < len; j++)
	{
		if(arr[j] == 1)
		{
			arr[i++] = arr[j];
		}
	}

	for(; i < len; i++)
	{
		arr[i] = 0;
	}

}

void printArray(int *arr, int len) 
{
	cout<<endl;
	for(int i = 0; i < len; i++)
	{
		cout<<" "<<arr[i];
	}
	cout<<endl;
}

int main()
{
	int array1[] = {1,0,1,0,1,1,0,1,1};
	cout<<"Original array 1: "; 
	int array1_len = sizeof(array1)/sizeof(array1[0]);
	printArray(array1, array1_len);
	put_zero_end(array1, sizeof(array1)/sizeof(array1[0]));
	cout<<"Modified Zero end array 1: "; 
	printArray(array1, array1_len);

	return 0;
}



		
		

