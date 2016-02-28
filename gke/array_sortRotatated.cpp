/*

Find an elem in sorted rotated array
Input:find5in{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14} Output: 8 (the index of 5 in the array)

*/



/* Algo: 

step 1: Find the rotate point using Binary search
step 2: perform two binary searches for the elem on the subarrays

*/

#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;





int bin_search(int *arr, int elem, int start, int end)
{

	if(arr == NULL || (start > end))
	{
		return -1;
	}


	int middle = (start + end) / 2;
	
	if(arr[middle] == elem)
	{
		return middle;
	}
	else if(arr[middle] > elem)
	{
		return bin_search(arr, elem, start, middle - 1);
	}
	else 
	{
		return bin_search(arr, elem, middle + 1, end);
	}

	
}


int find_pivot(int *arr, int start, int end)
{

	/* The algo for this is in three steps
	   Step 1: Find the middle elem.
	   Step 2: If the middle + 1 elem < middle elem, then return middle as the pivot
	   Step 3: Proceed appropriate pivot search in sub arrays whose start > end
	*/

	if(start > end)
		return -1;

	int middle = (start + end) / 2;

	if( (middle + 1) <= end )
	{
		if(arr[middle] > arr[middle + 1])
		{
			//This is the pivot point
			return middle + 1;
		}
	}
	if( (middle - 1) >= start)
	{
		if(arr[middle] < arr[middle - 1])
		{
		//This is the pivot point
		return middle;
		}
	}

	
	
	if( ((middle - 1) >= start) && arr[start] > arr[middle - 1])
	{
		return find_pivot(arr, start, middle - 1);
	}
	else
	{
		return find_pivot(arr, middle + 1, end);
	}

	



}




//This function returns -1 if not the elem is not found

int findElemIndex(int *arr, int x, int start, int end)
{

	if(arr == NULL)
	{
		return -1;
	}



	int pivot_index = find_pivot(arr, start, end);

	int index = bin_search(arr, x, start, pivot_index - 1);

	if( index == -1)
	{
		index = bin_search(arr, x, pivot_index, end);
	}

	return index;

}




int main()
{



	/* Test cases */

	int arr1[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

	int len = sizeof(arr1) / sizeof(arr1[0]);


	cout<<"Test Index of 15: 0 ==  "<<findElemIndex(arr1, 15, 0, len - 1)<<endl;
	cout<<"Test Index of 16: 1 ==  "<<findElemIndex(arr1, 16, 0, len - 1)<<endl;
	cout<<"Test Index of 19: 2 ==  "<<findElemIndex(arr1, 19, 0, len - 1)<<endl;
	cout<<"Test Index of 20: 3 ==  "<<findElemIndex(arr1, 20, 0, len - 1)<<endl;
	cout<<"Test Index of 25: 4 ==  "<<findElemIndex(arr1, 25, 0, len - 1)<<endl;
	cout<<"Test Index of 1: 5 ==  "<<findElemIndex(arr1, 1, 0, len - 1)<<endl;
	cout<<"Test Index of 3: 6 ==  "<<findElemIndex(arr1, 3, 0, len - 1)<<endl;
	cout<<"Test Index of 4: 7 ==  "<<findElemIndex(arr1, 4, 0, len - 1)<<endl;
	cout<<"Test Index of 5: 8 ==  "<<findElemIndex(arr1, 5, 0, len - 1)<<endl;
	cout<<"Test Index of 7: 9 ==  "<<findElemIndex(arr1, 7, 0, len - 1)<<endl;
	cout<<"Test Index of 10: 10 ==  "<<findElemIndex(arr1, 10, 0, len - 1)<<endl;
	cout<<"Test Index of 14: 11 ==  "<<findElemIndex(arr1, 14, 0, len - 1)<<endl;



	int arr2[] = {15, 16, 19, 20, 25, 27, 29, 31, 32, 33, 35, 37};

	int len2 = sizeof(arr2) / sizeof(arr2[0]);


	cout<<"Test Index of 15: 0 ==  "<<findElemIndex(arr2, 15, 0, len2 - 1)<<endl;
	cout<<"Test Index of 16: 1 ==  "<<findElemIndex(arr2, 16, 0, len2 - 1)<<endl;
	cout<<"Test Index of 19: 2 ==  "<<findElemIndex(arr2, 19, 0, len2 - 1)<<endl;
	cout<<"Test Index of 20: 3 ==  "<<findElemIndex(arr2, 20, 0, len2 - 1)<<endl;
	cout<<"Test Index of 25: 4 ==  "<<findElemIndex(arr2, 25, 0, len2 - 1)<<endl;
	cout<<"Test Index of 27: 5 ==  "<<findElemIndex(arr2, 27, 0, len2 - 1)<<endl;
	cout<<"Test Index of 29: 6 ==  "<<findElemIndex(arr2, 29, 0, len2 - 1)<<endl;
	cout<<"Test Index of 31: 7 ==  "<<findElemIndex(arr2, 31, 0, len2 - 1)<<endl;
	cout<<"Test Index of 32: 8 ==  "<<findElemIndex(arr2, 32, 0, len2 - 1)<<endl;
	cout<<"Test Index of 33: 9 ==  "<<findElemIndex(arr2, 33, 0, len2 - 1)<<endl;
	cout<<"Test Index of 35: 10 ==  "<<findElemIndex(arr2, 35, 0, len2 - 1)<<endl;
	cout<<"Test Index of 37: 11 ==  "<<findElemIndex(arr2, 37, 0, len2 - 1)<<endl;


	int arr3[] = {15, 16, 19, 20, 25, 27, 29, 31, 32, 33, 35, 14};

	int len3 = sizeof(arr3) / sizeof(arr3[0]);


	cout<<"Test Index of 15: 0 ==  "<<findElemIndex(arr3, 15, 0, len3 - 1)<<endl;
	cout<<"Test Index of 16: 1 ==  "<<findElemIndex(arr3, 16, 0, len3 - 1)<<endl;
	cout<<"Test Index of 19: 2 ==  "<<findElemIndex(arr3, 19, 0, len3 - 1)<<endl;
	cout<<"Test Index of 20: 3 ==  "<<findElemIndex(arr3, 20, 0, len3 - 1)<<endl;
	cout<<"Test Index of 25: 4 ==  "<<findElemIndex(arr3, 25, 0, len3 - 1)<<endl;
	cout<<"Test Index of 27: 5 ==  "<<findElemIndex(arr3, 27, 0, len3 - 1)<<endl;
	cout<<"Test Index of 29: 6 ==  "<<findElemIndex(arr3, 29, 0, len3 - 1)<<endl;
	cout<<"Test Index of 31: 7 ==  "<<findElemIndex(arr3, 31, 0, len3 - 1)<<endl;
	cout<<"Test Index of 32: 8 ==  "<<findElemIndex(arr3, 32, 0, len3 - 1)<<endl;
	cout<<"Test Index of 33: 9 ==  "<<findElemIndex(arr3, 33, 0, len3 - 1)<<endl;
	cout<<"Test Index of 35: 10 ==  "<<findElemIndex(arr3, 35, 0, len3 - 1)<<endl;
	cout<<"Test Index of 37: 11 ==  "<<findElemIndex(arr3, 14, 0, len3 - 1)<<endl;

	int arr4[] = {38, 16, 19, 20, 25, 27, 29, 31, 32, 33, 35, 37};

	int len4 = sizeof(arr4) / sizeof(arr4[0]);


	cout<<"Test Index of 38: 0 ==  "<<findElemIndex(arr4, 38, 0, len4 - 1)<<endl;
	cout<<"Test Index of 16: 1 ==  "<<findElemIndex(arr4, 16, 0, len4 - 1)<<endl;
	cout<<"Test Index of 19: 2 ==  "<<findElemIndex(arr4, 19, 0, len4 - 1)<<endl;
	cout<<"Test Index of 20: 3 ==  "<<findElemIndex(arr4, 20, 0, len4 - 1)<<endl;
	cout<<"Test Index of 25: 4 ==  "<<findElemIndex(arr4, 25, 0, len4 - 1)<<endl;
	cout<<"Test Index of 27: 5 ==  "<<findElemIndex(arr4, 27, 0, len4 - 1)<<endl;
	cout<<"Test Index of 29: 6 ==  "<<findElemIndex(arr4, 29, 0, len4 - 1)<<endl;
	cout<<"Test Index of 31: 7 ==  "<<findElemIndex(arr4, 31, 0, len4 - 1)<<endl;
	cout<<"Test Index of 32: 8 ==  "<<findElemIndex(arr4, 32, 0, len4 - 1)<<endl;
	cout<<"Test Index of 33: 9 ==  "<<findElemIndex(arr4, 33, 0, len4 - 1)<<endl;
	cout<<"Test Index of 35: 10 ==  "<<findElemIndex(arr4, 35, 0, len4 - 1)<<endl;
	cout<<"Test Index of 37: 11 ==  "<<findElemIndex(arr4, 37, 0, len4 - 1)<<endl;


	int arr5[] = {38, 16, 19, 20, 25, 27, 29, 31, 32};

	int len5 = sizeof(arr5) / sizeof(arr5[0]);


	cout<<"Test Index of 38: 0 ==  "<<findElemIndex(arr4, 38, 0, len4 - 1)<<endl;
	cout<<"Test Index of 16: 1 ==  "<<findElemIndex(arr4, 16, 0, len4 - 1)<<endl;
	cout<<"Test Index of 19: 2 ==  "<<findElemIndex(arr4, 19, 0, len4 - 1)<<endl;
	cout<<"Test Index of 20: 3 ==  "<<findElemIndex(arr4, 20, 0, len4 - 1)<<endl;
	cout<<"Test Index of 25: 4 ==  "<<findElemIndex(arr4, 25, 0, len4 - 1)<<endl;
	cout<<"Test Index of 27: 5 ==  "<<findElemIndex(arr4, 27, 0, len4 - 1)<<endl;
	cout<<"Test Index of 29: 6 ==  "<<findElemIndex(arr4, 29, 0, len4 - 1)<<endl;
	cout<<"Test Index of 31: 7 ==  "<<findElemIndex(arr4, 31, 0, len4 - 1)<<endl;
	cout<<"Test Index of 32: 8 ==  "<<findElemIndex(arr4, 32, 0, len4 - 1)<<endl;





	return 0;

}










