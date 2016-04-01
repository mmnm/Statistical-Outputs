/*

Please see 
https://www.youtube.com/watch?v=5td2QH-x5ck
for explanation
*/




#include<iostream>


using namespace std;


bool isSubsetSum(int *arr, int n, int sum)
{

	bool sum_table[n + 1][sum + 1];

	//Fill for init values

	for(int i = 0; i <= n; i++)
	{
		sum_table[i][0] = true;
	}

	for(int j = 1; j <= sum; j++)
	{
		sum_table[0][j] = false;
	}

	//Now start building the table

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= sum; j++)
		{
			sum_table[i][j] = sum_table[i-1][j];
			
			if( (sum_table[i][j] == false) && (j - arr[i - 1]) >= 0)
			{
				sum_table[i][j] = sum_table[i][j] || 
					sum_table[i - 1][j - arr[i - 1]];
			}
		}
	}

/*
	
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", sum_table[i][j]);
       printf("\n");
     } 

*/




	return sum_table[n][sum];
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
 
 if (isSubsetSum(set, n, sum) == true)
     printf("\nFound a subset with given sum %d", sum);
  else
     printf("No subset with given sum %d", sum);

printf("\n");
  
  if (isSubsetSum(set, n , sum) == true)
     printf("\nFound a subset with given sum %d", sum);
  else
     printf("No subset with given sum %d", sum);
printf("\n");

 if (isSubsetSum(set, n, sum1) == true)
     printf("Found a subset with given sum1 %d", sum1);
  else
     printf("No subset with given sum %d", sum1);

printf("\n");
  
  if (isSubsetSum(set, n, sum2) == true)
     printf("Found a subset with given sum2 %d", sum2);
  else
     printf("No subset with given sum %d", sum2);
printf("\n");

 if (isSubsetSum(set, n, sum3) == true)
     printf("Found a subset with given sum %d", sum3);
  else
     printf("No subset with given sum %d", sum3);

printf("\n");
  
  if (isSubsetSum(set, n, sum4) == true)
     printf("Found a subset with given sum %d", sum4);
  else
     printf("No subset with given sum %d", sum4);

printf("\n");

  if (isSubsetSum(set, n, sum5) == true)
     printf("Found a subset with given sum2 %d", sum5);
  else
     printf("No subset with given sum %d", sum5);

printf("\n");

 if (isSubsetSum(set, n, sum6) == true)
     printf("Found a subset with given sum %d", sum6);
  else
     printf("No subset with given sum %d", sum6);

printf("\n");
  
  if (isSubsetSum(set, n, sum7) == true)
     printf("Found a subset with given sum %d", sum7);
  else
     printf("No subset with given sum %d", sum7);

printf("\n");
return 0;
}





