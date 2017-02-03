/* Check if sum pair is there in an unsorted array  that equals to target 

E.g    {1,9,4,12,5,21,13,19,3,2}, 10  -> true

	9 -> true

	41 -> true
	
	46 ->true

		



*/




#include<iostream>
#include<map>

using namespace std;



bool is_sum_pair(int *arr, int len, int sum)
{
	if(arr == NULL || len <= 1)
	{
		return false;
	}	

	// We will use hash to store the diff and check if new_elem already 
	//exists in hash. If yes, then return true

	std::map<int, bool> hashSum;
	std::map<int, bool>::iterator it;

	for(int i = 0; i < len; i++)
	{
		int curElem = arr[i];

		it = hashSum.find(curElem);

		if(it != hashSum.end())
		{
			//Found pair
			return true;
		}
		else
		{
			//Put diff in hash
			hashSum[sum - curElem] = true;
		}
	}

	return false;

}
				


void printArr(int *arr, int len)
{
	cout<<endl;

	if(arr == NULL || len <= 0)
	{
		return;
	}

	for(int i = 0; i < len; i++)
	{
		cout<<" "<<arr[i];
	}
	cout<<endl;
}
int main()
{
	int array1[] = {1,9,4,12,5,21,13,19,3,2};
	int array1_len = sizeof(array1)/sizeof(array1[0]);

	//Test cases
	cout<<"Array1: "<<endl;
	printArr(array1, array1_len);

	cout<<"10 sum pair present in Array1 ? : "<<is_sum_pair(array1, 
						array1_len, 10)<<endl;

	cout<<"24 sum pair present in Array1 ? : "<<is_sum_pair(array1, 
						array1_len, 24)<<endl;

	cout<<"9 sum pair present in Array1 ? : "<<is_sum_pair(array1, 
						array1_len, 9)<<endl;

	cout<<"50 sum pair present in Array1 ? : "<<is_sum_pair(array1, 
						array1_len, 50)<<endl;

	cout<<"2 sum pair present in Array1 ? : "<<is_sum_pair(array1, 
						array1_len, 2)<<endl;

	cout<<"26 sum pair present in Array1 ? : "<<is_sum_pair(array1, 
						array1_len, 26)<<endl;

	cout<<"4 sum pair present in Array1 ? : "<<is_sum_pair(array1, 
						array1_len, 4)<<endl;

	cout<<"100 sum pair present in Array1 ? : "<<is_sum_pair(array1, 
						array1_len, 100)<<endl;

	cout<<"-5 sum pair present in Array1 ? : "<<is_sum_pair(array1, 
						array1_len, -5)<<endl;

}






