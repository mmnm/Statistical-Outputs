#include<iostream>


using namespace std;

#define R 3
#define C 3




void printMatrix(int *arr, int rows, int cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cout<<*(arr + i * cols + j)<<" ";
		}
		cout<<endl;
	}


}


void rotateAntiClock90(int *arr, int rows, int cols)
{
	int *rotatedArr = new int[rows * cols];

//Now we do a simple algo to fill the rotated array

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			int mod_i = rows - j - 1;
			int mod_j = i;

			*(rotatedArr + mod_i * cols + mod_j)	= *(arr + i * cols + j);
		}
	}


	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			*(arr + i * cols + j) = *(rotatedArr + i * cols + j);
		}
	}

	delete [] rotatedArr;

}	



int main()
{

	int arr[R][C] = { {1, 2, 3},	
	{4, 5, 6},
	{7, 8, 9}
};

int arr1[4][4] = { {1, 2, 3, 4},	
{5, 6, 7, 8},
{9,10, 11, 12},
{13,14,15,16}
};

	/* Test case 1*/
	printMatrix((int *)arr, R, C);
	cout<<endl;

	rotateAntiClock90((int *)arr, R, C);

	printMatrix((int *)arr, R, C);
	cout<<endl;


	cout<<endl;
	cout<<endl;
	/* Test case 2*/

	printMatrix((int *)arr1, 4, 4);
	cout<<endl;

	rotateAntiClock90((int *)arr1, R + 1, C + 1);

	printMatrix((int *)arr1, 4, 4);
	cout<<endl;

}







