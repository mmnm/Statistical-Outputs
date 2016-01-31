//merge routine with combine routine
/*
Given array is
12 11 13 5 6 7

Sorted array is
5 6 7 11 12 13
*/

#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;

void combine_routine(int *arr, int start, int mid, int end);
void merge_routineHelper(int *arr, int start, int end);

void merge_routine(int *arr, int len)
{
	if(arr == NULL)
		return;

	merge_routineHelper(arr, 0, len - 1);
	
}

void merge_routineHelper(int *arr, int start, int end)
{
	if(arr == NULL || start >= end)
		return;

	int middle = (start + end) / 2;
	merge_routineHelper(arr, start, middle);
	merge_routineHelper(arr, middle + 1, end);
	combine_routine(arr, start, middle, end);

}

void combine_routine(int *arr, int start, int mid, int end)
{
	if( (arr == NULL) || (start >= end) || (mid > end) || (mid < start)) 
	{
		return;
	}

	//Copy the elems in temp list 
	int len1 = mid - start + 1;
	int len2 = end - mid;

	int arr1[len1];
	int arr2[len2];

	int j = 0;
	for(int i = start; i <= mid; i++)
	{
		arr1[j++] = arr[i];
	}
	j = 0;
	int i;
	for(i = mid + 1; i <= end; i++)
	{
		arr2[j++] = arr[i];
	}

	
	//Combine the sorted arrays
	for(i = 0, j = 0; i < len1 && j < len2;)
	{
		if(arr1[i] > arr2[j])
		{
			arr[start++] = arr2[j++];
		}
		else
		{
			arr[start++] = arr1[i++];
		}
	}

	while(i < len1)
	{
		arr[start++] = arr1[i++];
	}

	while(j < len2)
	{
		arr[start++] = arr2[j++];
	}


}

void printArr(int *arr, int len)
{

	for(int i = 0; i < len; i++)
	{
		cout<<" "<<arr[i];
	}
	cout<<endl;

}

int main()
{
	/*Test cases*/
	int arr[] = {12,11,13,5,6,7};
	int len = sizeof(arr)/sizeof(arr[0]);
	printArr(arr, len);
	merge_routine(arr, len);
	cout<<"After merge sort: "<<endl;
	printArr(arr, len);

	cout<<"**************"<<endl;
	int arr1[] = {12};
	int len1 = sizeof(arr1)/sizeof(arr1[0]);
	printArr(arr1, len1);
	merge_routine(arr1, len1);
	cout<<"After merge sort: "<<endl;
	printArr(arr1, len1);


	cout<<"**************"<<endl;
	int arr2[] = {12, 13};
	int len2 = sizeof(arr2)/sizeof(arr2[0]);
	printArr(arr2, len2);
	merge_routine(arr2, len2);
	cout<<"After merge sort: "<<endl;
	printArr(arr2, len2);

	cout<<"**************"<<endl;
	int arr3[] = {13, 12};
	int len3 = sizeof(arr3)/sizeof(arr3[0]);
	printArr(arr3, len3);
	merge_routine(arr3, len3);
	cout<<"After merge sort: "<<endl;
	printArr(arr3, len3);

	cout<<"**************"<<endl;

	return 0;
	
}




