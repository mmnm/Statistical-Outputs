
/*

Print matrix spiral using pointers passes to handle various arrays

*/

#include<iostream>

using namespace std;

#define R 4
#define C 4

void printSpiral(int rows, int cols, int *arr)
{
	if(arr == NULL)
	{
		return;
	}


	int left = 0;
	int right = cols - 1;
	int top = 0;
	int bottom = rows - 1;

	for(;;)
	{
		if(left > right || top > bottom)
		{
			break;
		}

//Print left to right
		for(int i = left; i <= right; i++)
		{
			cout<<" "<<*((arr + cols * top) + i);
		}
		top++;
		if(left > right || top > bottom)
		{
			break;
		}

		for(int i = top; i <= bottom; i++)
		{
//cout<<" "<<arr[i][right]; 
			cout<<" "<< *((arr + cols*i) + right); 
		}
		right--;

		if(left > right || top > bottom)
		{
			break;
		}
		for(int i = right; i >= left; i--)
		{
//cout<<" "<<arr[bottom][i];
			cout<<" "<<*((arr + cols * bottom) + i);
		}
		bottom--;

		if(left > right || top > bottom)
		{
			break;
		}
		for(int i = bottom; i >= top; i--)
		{
//cout<<" "<<arr[i][left];
			cout<<" "<<*((arr + cols*i) + left);
		}
		left++;

	}

}


int main()
{

/* Test case 1*/
	int arr[][C] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	int m = 4;
	int n = 4;
	printSpiral(m, n, (int *)arr);


	cout<<"\nTest case 2"<<endl;

	int a[][6] = { {1,  2,  3,  4,  5,  6},
	{7,  8,  9,  10, 11, 12},
	{13, 14, 15, 16, 17, 18}
};	

printSpiral(3, 6, (int *)a);

}


