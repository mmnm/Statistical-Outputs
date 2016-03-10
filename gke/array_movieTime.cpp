/*

Write a function that takes an integer flightLength (in minutes) and an array of integers movieLengths (in minutes) and returns a boolean indicating whether there are two numbers in movieLengths whose sum equals flightLength.

When building your function:

Assume your users will watch exactly two movies
Don't make your users watch the same movie twice
Optimize for runtime over memory

*/





#include<map>
#include<iostream>

using namespace std;


 






int * whichMoviesToWatch(int movieLength, int *arr, int arr_len)
{

	if(arr == NULL || arr_len < 2)
	{
		return NULL;
	}


	//This hash is used to store the diff at each point
	std::map<int, int> movieHash;
	std::map<int, int>::iterator it;

	//Build and return if found in the same step

	for(int i = 0; i < arr_len; i++)
	{
		int cur_elem = arr[i];

			


		it = movieHash.find(cur_elem);

		if(it != movieHash.end())
		{
			int elem1 = arr[it->second];
			int *res_arr = new int[2];
	
			//We found the pair
			//Build the result and return it
			res_arr[0] = elem1;
			res_arr[1] = cur_elem;

			return res_arr;
		}


		//Build the sumHash

		movieHash[movieLength - cur_elem] = i;
	}

	
		
	return NULL;
	
				
	
}


int main()
{

	//Test cases
	int arr1[]= {2,5,7,8,9};
	int *ptr = whichMoviesToWatch(11, arr1, sizeof(arr1)/sizeof(arr1[0]));
	//int *ptr = whichMoviesToWatch(5, arr1, sizeof(arr1)/sizeof(arr1[0]));

	if(ptr != NULL)
	{
		cout<<"Movie pair len is: "<<ptr[0]<<" and "<<ptr[1]<<endl;
	}
	else
	{
		cout<<"Not found"<<endl;
	}
		
	



	delete [] ptr;
	ptr = NULL;

	int arr2[]= {2,5};
	ptr = whichMoviesToWatch(11, arr2, sizeof(arr2)/sizeof(arr2[0]));

	if(ptr != NULL)
	{
		cout<<"Yo Movie pair len is: "<<ptr[0]<<" and "<<ptr[1]<<endl;
	}
	else
	{
		cout<<"Not found"<<endl;
	}

	

	
	return 0;


}

	
	





