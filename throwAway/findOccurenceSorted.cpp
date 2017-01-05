/* Find the number of times a number appears in a sorted array */


#include<iostream>

using namespace std;







int findBinStart(int *arr, int start, int end, int num)
{

	if(arr == NULL || start > end)
	{
		return -1;
	}

	int mid = (start + end) / 2;
	
	if(arr[mid] == num)
	{
		if((mid - 1) < 0)
		{
			return mid;
		}

		if(arr[mid - 1] != num)
		{
			return mid;
		}
		else 
		{
			return findBinStart(arr, start, mid - 1, num);
		}

	}
	else if(arr[mid] < num)
	{
		return findBinStart(arr, mid + 1, end, num);
	}
	else 
	{
		return findBinStart(arr, start, mid - 1, num);
	}

}	
		
	

int findBinEnd(int *arr, int start, int end, int num, int len)
{

	if(arr == NULL || start > end)
	{
		return -1;
	}

	int mid = (start + end) / 2;
	
	if(arr[mid] == num)
	{
		if((mid + 1) > (len - 1) ) 
		{
			return mid;
		}

		if(arr[mid + 1] != num)
		{
			return mid;
		}
		else 
		{
			return findBinEnd(arr, mid + 1, end, num, len);
		}

	}
	else if(arr[mid] < num)
	{
		return findBinEnd(arr, mid + 1, end, num, len);
	}
	else 
	{
		return findBinEnd(arr, start, mid - 1, num, len);
	}

}	


int findOccurence(int *arr, int len, int num)
{
	
	if(arr == NULL || len <= 0)
	{
		return -1;
	}

	int start_index = findBinStart(arr, 0, len - 1, num);

	if(start_index == -1)
	{
		return -1;
	}
	
	int end_index = findBinEnd(arr, 0, len - 1, num, len);

	if(end_index == -1)
	{
		return -1;
	}

	return end_index - start_index + 1;



}






int main()
{


	//Test input 1
	int array1[] = {1,1,2,2,2,2,3,3,5,5,5,5,5,9,11,11,11,11,11,14,14,15,15,17};
	cout<<"Input array1: {1,1,2,2,2,2,3,3,5,5,5,5,5,9,11,11,11,11,11,14,14,15,15,17}"<<endl; 
	cout<<"Input number is 1 and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 1)<<endl;
	cout<<"Input number is 2 and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 2)<<endl;
	cout<<"Input number is 3 and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 3)<<endl;
	cout<<"Input number is 5 and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 5)<<endl;
	cout<<"Input number is 9 and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 9)<<endl;
	cout<<"Input number is 11 and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 11)<<endl;
	cout<<"Input number is 14 and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 14)<<endl;
	cout<<"Input number is 15 and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 15)<<endl;
	cout<<"Input number is 17 and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 17)<<endl;
	cout<<"Input number is 21  and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 21)<<endl;
	cout<<"Input number is 0  and count is: "<<findOccurence(array1, sizeof(array1)/sizeof(array1[0]), 0)<<endl;


	return 0;


}
