#include<iostream>
#include<algorithm>
#include<map>


using namespace std;

bool isSumPair(int *arr, int len, int sum) 
{
	if(arr == NULL)
	{
		return false;
	}

	/* 
		use hash table 
		store diff values and check for a new elem if it exists in hash

	*/	

	std::map<int,int> sumHash;
	std::map<int,int>::iterator it;

	for(int i = 0; i < len; i++)
	{
		int curElem = arr[i];
		
		it = sumHash.find(curElem);

		if(it != sumHash.end())
		{
			//Found
			return true;
		}
		
		sumHash[sum-curElem] = i;
	}

	return false;

}

int main()
{
	int arr[] = {2, 9, 3, 8, 5, 11, 12, 1, 22};
	int arr2[] = {2, 9};
	int arr3[] = {2};


	cout<<" isSumPair(9):  "
		<<isSumPair(arr, sizeof(arr)/sizeof(arr[0]), 9)<<endl;
	cout<<" isSumPair(24):  "
		<<isSumPair(arr, sizeof(arr)/sizeof(arr[0]), 24)<<endl;
	cout<<" isSumPair(44):  "
		<<isSumPair(arr, sizeof(arr)/sizeof(arr[0]), 44)<<endl;
	cout<<" isSumPair(23):  "
		<<isSumPair(arr, sizeof(arr)/sizeof(arr[0]), 23)<<endl;
	cout<<" isSumPair(11):  "
		<<isSumPair(arr, sizeof(arr2)/sizeof(arr[2]), 11)<<endl;
	cout<<" isSumPair(2):  "
		<<isSumPair(arr, sizeof(arr3)/sizeof(arr3[0]), 2)<<endl;
	return 0;

		
}	



	




