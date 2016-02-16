#include<iostream>

using namespace std;


int findLeftBinSearch(int *arr, int start, int end, int value)
{
	if( start > end )
	{
		return -1;
	}

	
	int mid = (start + end) / 2;

	if(arr[mid] == value)
	{
		if(mid == start)
		{
			return mid;
		}
		else if(arr[mid - 1] != value)
		{
			return mid;
		}
		else 
		{
			return findLeftBinSearch(arr, start, mid - 1, value);
		}

	}
	else if(arr[mid] < value)
	{
		return findLeftBinSearch(arr, mid + 1, end, value);
	}
	else if(arr[mid] > value)
	{
		return findLeftBinSearch(arr, start, mid - 1, value);
	}

	return -1;		
	
}

/*
	Test simulation example
                              m
                        0 1 2 3 4 5 6 7 8 9 1 1 2 3 4 5 6 7 8 9 2 1 2 3 4 5
	//int arr1[] = {1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,4,4,4,4,4,5,5,5,5,5,6};
			      s
			        e
			

*/

int findRightBinSearch(int *arr, int start, int end, int value)
{
	
	if( start > end )
	{
		return -1;
	}

	
	int mid = (start + end) / 2;

	if(arr[mid] == value)
	{
		if(mid == end)
		{
			return mid;
		}
		else if(arr[mid + 1] != value)
		{
			return mid;
		}
		else 
		{
			return findRightBinSearch(arr, mid + 1, end, value);
		}

	}
	else if(arr[mid] < value)
	{
		return findRightBinSearch(arr, mid + 1, end, value);
	}
	else if(arr[mid] > value)
	{
		return findRightBinSearch(arr, start, mid - 1, value);
	}
		
	return -1;
	
}






int maxCountSorted(int *arr, int len, int value)
{

	if(arr == NULL || len <= 0)
	{
		return -1;
	}


	int start_index = findLeftBinSearch(arr, 0, len - 1, value);

	if(start_index == -1)
	{
		//Value doesn't exist
		return -1;
	}

	int end_index = findRightBinSearch(arr, 0, len - 1, value);
	if(end_index == -1)
	{
		cout<<"Something wrong, Debug this"<<endl;
		return -1;
	}
	
	cout<<"Start index and end_index are: "<<start_index<<" "<<end_index<<endl;
	return end_index - start_index + 1;

}



int main()
{
	int arr1[] = {1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6};
	

	cout<<"arr1 search, 1: "<<maxCountSorted(arr1, sizeof(arr1)/sizeof(arr1[0]), 1)<<endl;
	cout<<"arr1 search, 2: "<<maxCountSorted(arr1, sizeof(arr1)/sizeof(arr1[0]), 2)<<endl;
	cout<<"arr1 search, 3: "<<maxCountSorted(arr1, sizeof(arr1)/sizeof(arr1[0]), 3)<<endl;
	cout<<"arr1 search, 4: "<<maxCountSorted(arr1, sizeof(arr1)/sizeof(arr1[0]), 4)<<endl;
	cout<<"arr1 search, 5: "<<maxCountSorted(arr1, sizeof(arr1)/sizeof(arr1[0]), 5)<<endl;
	cout<<"arr1 search, 6: "<<maxCountSorted(arr1, sizeof(arr1)/sizeof(arr1[0]), 6)<<endl;
	cout<<"arr1 search, 11: "<<maxCountSorted(arr1, sizeof(arr1)/sizeof(arr1[0]), 11)<<endl;
	cout<<"arr1 search, -21: "<<maxCountSorted(arr1, sizeof(arr1)/sizeof(arr1[0]), -21)<<endl;
	return 0;
}


	
