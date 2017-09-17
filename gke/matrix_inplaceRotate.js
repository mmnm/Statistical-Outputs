/* 

In place rotate matrix by 90 degree, given N*N matrix



Algo:


1. Find the number of levels to transform from 
  outer to inner. This would be N / 2 levels
2. For each level, Rotate corner 4 elems and shift one elem, 
to find new corners and rotate till all elems 
have been rotated.


*/




#include<iostream>
#define N 4

using namespace std;


void rotateMatrix(int matrix[][N])
{
  
  int levels = N / 2;
  int rows = N;
  int cols = N;
  
  
  
  for(int i = 0; i < levels; i++)
  {
    
    //Initialize the corners start_row, end_row, start_col,
    // end_col
    int start_row = i;
    int end_row = rows - 1 - i;
    int start_col = i;
    int end_col = cols - 1 - i;
    
    //Now transform all corner elems in this level
    
    for(int j = 0; j < (end_row - start_row); j++)
    {
      //Transform the elems using just one temp
      //temp = a;
      int temp = matrix[start_row][start_col + j];
      //a = d;
      matrix[start_row][start_col + j] = 
        matrix[end_row - j][start_col];
      //d = c;
      matrix[end_row - j][start_col] = 
        matrix[end_row][end_col - j];
      //c = b
        matrix[end_row][end_col - j] = 
          matrix[start_row + j][end_col];
      //b = temp;
        matrix[start_row + j][end_col] = temp;
      
    }
    
  }
  
}

// Function to print the matrix
void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);
 
        printf("\n");
    }
    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    // Test Case 1
    int mat[N][N] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
 
 
    // Tese Case 2
    /* int mat[N][N] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                    };
     */
 
    // Tese Case 3
    /*int mat[N][N] = {
                    {1, 2},
                    {4, 5}
                };*/
 
    //displayMatrix(mat);
 
    rotateMatrix(mat);
 
    // Print rotated matrix
    displayMatrix(mat);
 
    return 0;
}






