#include<iostream>

using namespace std;


void printArr(int *arr, int len)
{
	cout<<endl;

	for(int i = 0; i < len; i++)
	{
		cout<<" " <<arr[i];
	}

	cout<<endl;
	
}

int partition(int *arr, int start, int end)
{
	if(start > end)
	{
		return -1;
	}

	if(start == end)
	{
		return start;
	}

	int part_elem = arr[start];

	int i = start;

	for(int j = start + 1; j <= end; j++)
	{
		//Swap ith + 1 if less than part_elem
		int cur_elem = arr[j];		

		if(cur_elem < part_elem)
		{
			arr[j] = arr[i + 1];
			arr[i + 1] = cur_elem;
			i++;
		}
 	}
	//Last swap for putting part elem in place

	arr[start] = arr[i];
	arr[i] = part_elem;

	return i;

}
	
	





void quick_sort(int *arr, int start, int end)
{
	if(start > end)
	{
		return;
	}

	int part_index = partition(arr, start, end);

	if(part_index == -1)
	{
		cout<<"Error, Part_index debug required"<<endl;
		return;
	}

	quick_sort(arr, start, part_index - 1);
	quick_sort(arr, part_index + 1, end);
}



int main()
{

	int array1[] = {5,2,9,11,4,1,14,12};
	int array1_len = sizeof(array1)/sizeof(array1[0]);
	cout<<"Test case 1: Orig array"<<endl;
	printArr(array1, array1_len);

	cout<<"Test case 1: Sorted array"<<endl;
	
	quick_sort(array1, 0, array1_len - 1);
	printArr(array1, array1_len);

	cout<<"********************"<<endl;

	int array2[] = {4,2,7,3,9,11};
	int array2_len = sizeof(array2)/sizeof(array2[0]);
	cout<<"Test case 2: Orig array"<<endl;
	printArr(array2, array2_len);

	cout<<"Test case 2: Sorted array"<<endl;
	
	quick_sort(array2, 0, array2_len - 1);
	printArr(array2, array2_len);

	cout<<"********************"<<endl;
	int array3[] = {1,2,3,4,5,6,7,8,9};
	int array3_len = sizeof(array3)/sizeof(array3[0]);
	cout<<"Test case 3: Orig array"<<endl;
	printArr(array3, array3_len);

	cout<<"Test case 3: Sorted array"<<endl;
	
	quick_sort(array3, 0, array3_len - 1);
	printArr(array3, array3_len);

	cout<<"********************"<<endl;
	int array4[] = {9,8,7,6,5,4,3,2,1};
	int array4_len = sizeof(array4)/sizeof(array4[0]);
	cout<<"Test case 3: Orig array"<<endl;
	printArr(array4, array4_len);

	cout<<"Test case 3: Sorted array"<<endl;
	
	quick_sort(array4, 0, array4_len - 1);
	printArr(array4, array4_len);
	return 0;
	
}
