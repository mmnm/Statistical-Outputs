
/*
Given an array A[] and a number x, check for pair in A[] with sum as x

int A[] = {1, 4, 45, 6, 10, 8};

int n = 16;  : true

*/


#include<iostream>
#include<map>

using namespace std;



bool isSumPair(int *arr, int arr_len, int elem)
{

	if(arr == NULL || arr_len <= 1)
	{
		return false;
	}



	std::map<int, int> hashSum;
	std::map<int, int>::iterator it;


	for(int i = 0; i < arr_len; i++)
	{
		int curElem = arr[i];

		it = hashSum.find(curElem);

		if(it != hashSum.end())
		{

//Pair found
			cout<<"Pairs found for"<<elem<<": "<< arr[it->second] <<", "<<curElem<<endl;
			return true;
		}

		hashSum[elem - curElem] = i;
	}

	return false;

}




int main()
{

	int arr1[] = {1, 4, 45, 6, 10, 8};


	cout<<"Returned pair Value for 16: "<<isSumPair(arr1, sizeof(arr1) / sizeof(arr1[0]) , 16)<<endl;
	cout<<"Returned pair Value for 9: "<<isSumPair(arr1, sizeof(arr1) / sizeof(arr1[0]) , 9)<<endl;
	cout<<"Returned pair Value for 10: "<<isSumPair(arr1, sizeof(arr1) / sizeof(arr1[0]) , 10)<<endl;
	cout<<"Returned pair Value for 14: "<<isSumPair(arr1, sizeof(arr1) / sizeof(arr1[0]) , 14)<<endl;
	cout<<"Returned pair Value for 12: "<<isSumPair(arr1, sizeof(arr1) / sizeof(arr1[0]) , 12)<<endl;
	cout<<"Returned pair Value for 55: "<<isSumPair(arr1, sizeof(arr1) / sizeof(arr1[0]) , 55)<<endl;
	cout<<"Returned pair Value for 13: "<<isSumPair(arr1, sizeof(arr1) / sizeof(arr1[0]) , 13)<<endl;
	cout<<"Returned pair Value for 23: "<<isSumPair(arr1, sizeof(arr1) / sizeof(arr1[0]) , 23)<<endl;
	cout<<"Returned pair Value for 8: "<<isSumPair(arr1, sizeof(arr1) / sizeof(arr1[0]) , 8)<<endl;

	return 0;

}



