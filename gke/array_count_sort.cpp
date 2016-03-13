


#include<iostream>
using namespace std;









int max_range(int *arr, int len)
{

	if(arr == NULL || len <= 0)
	{
		return 0;

	}

	int max = 0;

	for(int i = 0; i < len; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
	}


	return max;



}


void countSort(int *arr, int len)
{

	if(arr == NULL)
	{
		return;
	}

	//Output array
	int output_arr[len];

	//Create a counts array after finding the max_range and init to 0

	int max = max_range(arr, len);

	int *count_arr = new int[max + 1];
	for(int i = 0; i <= max; i++)
	{
		count_arr[i] = 0;
	}



	//Create count array

	for(int i = 0; i < len; i++)
	{
		int cur = arr[i];
		
		count_arr[cur]++;
	}

	//Create count array as a aggeregated sum

	for(int i = 1; i <= max; i++)
	{
		count_arr[i] += count_arr[i - 1];
	}

	//Now create the output array with sorted values

	for(int i = 0; i < len; i++)
	{
		int cur = arr[i];

		

		output_arr[count_arr[cur] - 1] = cur;
		count_arr[cur]--;
	}

	//Copy output array and return

	for(int i = 0; i < len; i++)
	{
		arr[i] = output_arr[i];
	}

}




// Driver program to test above function
int main()
{
    int arr[] = {0,3,2,3,3,0,5,2,3};
 
    countSort(arr, sizeof(arr)/sizeof(arr[0]));
 
    printf("Sortedarray is \n");

   for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
   {
	cout<<arr[i]<<" ";
		
    }
	
    return 0;
}		
		
	
	
		
	
	


	






