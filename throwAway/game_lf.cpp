/* Debugging Learning:

Be vary of incoming variable names to a function never name it to generic i, j
as they will often be overwritten as part of loop variable

Before
int countNeighbors(vector<vector<int>> board, int i, int j) 

After
int countNeighbors(vector<vector<int>> board, int r_x, int r_y) 
*/

#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countNeighbors(vector<vector<int>> board, int r_x, int r_y) 
    {
        //Error checks
        /* 
                1 1 1 
                1 1 1
                1 1 1
        
        */
        
        int rows = board.size();
        int cols = board[0].size();
        
        int neigbor_rows[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int neigbor_cols[] = {1, 1, 1, 0, -1, -1, -1, 0};
        
        int max_size = sizeof(neigbor_rows)/sizeof(neigbor_rows[0]);
     
        int count = 0;
        cout<<"\n\nFinding neigbors for i,j: "<<r_x<<","<<r_y<<endl;  
      
        for(int i = 0; i < max_size; i++)
        {
            cout<<"\nNeighbor rows for i: "<<i<<": "<<neigbor_rows[i]<<endl;
                  cout<<"\nNeighbor cols for i: "<<i<<": "<<neigbor_cols[i]<<endl;
          
            int cur_x = neigbor_rows[i] + r_x;
            int cur_y = neigbor_cols[i] + r_y;
          
          cout<<"Generated cur_x, cur_y: "<<cur_x<<","<<cur_y<<endl; 
            
            if(cur_x >= 0 && cur_x < rows && cur_y >= 0 && cur_y < cols)
            {
                cout<<"Valid cur_x, cur_y: "<<cur_x<<","<<cur_y<<endl; 
                int cur_value = board[cur_x][cur_y];
                cout<<"cur_board_val: "<<cur_value<<endl;
                
                if(cur_value == 1)
                {
                    count++;
                }
            }
            
        }
        
        cout<<"\n************"<<endl;
        return count;
    
        
    }
    
    void gameOfLife(vector<vector<int>>& board) 
    {
        
        int rows = board.size();
        if(rows == 0)
        {
            return;
        }
        
        int cols = board[0].size();
        
        vector<vector<int>> res = board;
        
        //Reset all to 0 default values
        for(int i = 0; i < rows; i++)
        {
            std::fill(res[i].begin(), res[i].end(), 0);
        }
        
       
        
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                int count = countNeighbors(board, i, j);
                int curVal = board[i][j];
                cout<<"\n\ncurVal is: "<<curVal<<endl;
                cout<<"count is: "<<count<<endl;
                
                if(curVal == 1)
                {
                    
                    if(count == 2 || count == 3)
                    {
                        res[i][j] = 1;
                    }
                }
                else if(curVal == 0)
                {
                    if(count == 3)
                    {
                        res[i][j] = 1;
                    }
                }        
            }
        }
        
        //Copy back 
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                board[i][j] = res[i][j];
            }
        }
  
    }
};

void printVector(vector<vector<int>> test)
{
  cout<<"\n\nAre we here"<<endl;
  int rows = test.size();
  
  if(rows == 0)
  {
    return;
  }
  
  int cols = test[0].size();
  
  
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols ; j++)
    {
      cout<<test[i][j]<<" ";
    }
    cout<<endl;
  }
  
}

int main()
{
  vector<vector<int>> test = {{1,1}, {1,0}};

  Solution A;
  
  A.gameOfLife(test);
  
  printVector(test);
  
  
  return 0;
  
}
  
  
