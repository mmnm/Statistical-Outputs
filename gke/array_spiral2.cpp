#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0)
        {
            return res;
        }
        //At each level do this 
        //Move from top_left - > top_right; top_right ->bottom_right
        //bottom_right->bottom_left; bottom_left -> top_left
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int levels = cols / 2;
        
        
        int left_col = 0;
        int right_col = cols - 1;
        int top_row = 0;
        int bottom_row = rows - 1;
        
        for(;left_col <= right_col && top_row <= bottom_row;)
        {
     
            //Print left to right cols, constant row
            for(int t = left_col; 
                (left_col <= right_col && top_row <= bottom_row) &&
                t <= right_col; t++)
            {
                cout<<"Print1:: "<<matrix[top_row][t]<<endl;
                res.push_back(matrix[top_row][t]);    
            }
            top_row++;
            
             //Print top to bottom, keeping constant col
            for(int t = top_row; 
                (left_col <= right_col && top_row <= bottom_row) &&
                t <= bottom_row; t++)
            {
                cout<<"Print2:: "<<matrix[t][right_col]<<endl;
                res.push_back(matrix[t][right_col]);    
            }
            right_col--;
            
              //Print right to left cols, keeping constant row
            for(int t = right_col; 
               (left_col <= right_col && top_row <= bottom_row) &&
                (t >= left_col); t--)
            {
                cout<<"Print3:: "<<matrix[bottom_row][t]<<endl;
                res.push_back(matrix[bottom_row][t]);    
            }
            bottom_row--;
            
              //Print bottom to top rows, keeping constant co;
            for(int t = bottom_row; 
                (left_col <= right_col && top_row <= bottom_row) &&
                (t >= top_row); t--)
            {
                 
                  cout<<"Print4:: "<<matrix[t][left_col]<<endl;
                res.push_back(matrix[t][left_col]);    
            }
            left_col++;
              
            
        }
        
        return res;

        
    }
};

void printV(vector<int> res)
{
	cout<<endl;
	for(int i = 0; i < res.size(); i++)
	{
		cout<<" " <<res[i];	
	}
	cout<<endl;
}


int main()
{
	vector<vector<int>> matrix = {{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}};

	Solution A;

	vector<int> res; 

	res = A.spiralOrder(matrix);
	
	printV(res);


	return 0;
}
