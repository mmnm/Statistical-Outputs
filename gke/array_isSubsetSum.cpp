#include<iostream>


using namespace std;








bool isSubsetSum(int *arr, int n, int sum)
{
	if(sum == 0)
	{
		return true;
	}

	if( (n < 0) && (sum > 0) )
	{
		return false;
	}
	if(n < 0)
	{
		return false;
	}


	if( isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n]) )
	{
		return true;
	}
	return false;
}


// Driver program to test above function
int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int sum1 = 3;
  int sum2 = 19;
  int sum3 = 20;
  int sum4 = 21;
  int sum5 = 10;
  int sum6 = 1;
  int sum7 = 125;
  int n = sizeof(set)/sizeof(set[0]);
 
 if (isSubsetSum(set, n - 1, sum) == true)
     printf("\nFound a subset with given sum %d", sum);
  else
     printf("No subset with given sum %d", sum);

printf("\n");
  
  if (isSubsetSum(set, n - 1, sum) == true)
     printf("\nFound a subset with given sum %d", sum);
  else
     printf("No subset with given sum %d", sum);
printf("\n");

 if (isSubsetSum(set, n - 1, sum1) == true)
     printf("Found a subset with given sum1 %d", sum1);
  else
     printf("No subset with given sum %d", sum1);

printf("\n");
  
  if (isSubsetSum(set, n - 1, sum2) == true)
     printf("Found a subset with given sum2 %d", sum2);
  else
     printf("No subset with given sum %d", sum2);
printf("\n");

 if (isSubsetSum(set, n - 1, sum3) == true)
     printf("Found a subset with given sum %d", sum3);
  else
     printf("No subset with given sum %d", sum3);

printf("\n");
  
  if (isSubsetSum(set, n - 1, sum4) == true)
     printf("Found a subset with given sum %d", sum4);
  else
     printf("No subset with given sum %d", sum4);

printf("\n");
  if (isSubsetSum(set, n - 1, sum5) == true)
     printf("Found a subset with given sum2 %d", sum5);
  else
     printf("No subset with given sum %d", sum5);

printf("\n");
 if (isSubsetSum(set, n - 1, sum6) == true)
     printf("Found a subset with given sum %d", sum6);
  else
     printf("No subset with given sum %d", sum6);

printf("\n");
  
  if (isSubsetSum(set, n - 1, sum7) == true)
     printf("Found a subset with given sum %d", sum7);
  else
     printf("No subset with given sum %d", sum7);

printf("\n");
return 0;
} 
