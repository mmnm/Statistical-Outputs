/*
You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.


Input:
int arr1[] = [1,5,9,12,15,.......]
int arr2[] = [2,6,11,13]

Output
arr1[] = [1,2,5,6,11,12,13,15]


*/



#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;




void mergeArrays(int *arr1, int arr1_len, int last_elem_len_arr1, int *arr2, int arr2_len)
{


	//Since we have to merge in the same array, there are two ways to do this
	// #1 Use another array for the result for the combine step and then merge the result back
	// #2 copy from behind of array1 in combine step, since there is enough space
	// We will go with #2

	


	//Algo start copying backward the larger value of the lists

	int i = last_elem_len_arr1 - 1;
	int j = arr2_len - 1;
	int k = arr1_len - 1;



	for(; (i >= 0) || (j >= 0);)
	{
		if((i >= 0) && (j >= 0))
		{
			if(arr1[i] > arr2[j])
			{
				arr1[k--] = arr1[i--];
			}
			else 
			{
				arr1[k--] = arr2[j--];
			}
		}
		else if((i >= 0))
		{
			arr1[k--] = arr1[i--];
		}
		else if((j >= 0))
		{
			arr1[k--] = arr2[j--];
		}
		else
		{
			cout<<"This should not have happened. Debug this"<<endl;
		}


	}


}


#define ARR1_LEN 8


int main()
{

	int *arr1 = new int[ARR1_LEN];
	/* Init step for array 1*/	
	arr1[0] = 1;
	arr1[1] = 5;
	arr1[2] = 9;
	arr1[3] = 12;
	arr1[4] = 15;
	 
	

	int arr2[] = {2,6,11,13};
	
	int len = ARR1_LEN;
	int len2 = sizeof(arr2)/sizeof(arr2[0]);

	

	mergeArrays(arr1, len, 5, arr2, len2);

	
	for(int i = 0; i < len; i++)
	{
		cout<<" "<<arr1[i];
	}
	
	cout<<endl;
	return 0;
}



