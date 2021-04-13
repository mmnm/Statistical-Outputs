
#include <iostream>
#include<vector>

using namespace std;



/* 
Given a sorted array in non-decreasing order, return an array of squares of each number, also in non-decreasing order. For example:

[-4,-2,-1,0,3,5] -> [0,1,4,9,16,25]
  n           p

2, 9

res
[0, 1, 2, 9, 16, 25]
 
tests: Empty, all neg, all pos, mix, ...

API: vector<int> squares_sorted(vector<int> inp);

algo: 
Scan for the first positive elem; Put in res vector the largest 


*/



class Solution { 
  
  public: 
  
  int sq(int inp) {
    
   return inp * inp; 
    
  }
  
  int findFirstPos(vector<int> inp) { 
    
   //Error handling assumed
    int ret = inp.size(); 
    for(int i = 0; i < inp.size(); i++) {
      
      if(inp[i] >= 0) {
        ret = i;
        break;
      }
    }
    
    return ret;
      
  }
  
  vector<int> squares_sorted(vector<int> inp) {
    
    vector<int> res; 
    
    //Error handling 
    if(inp.size() == 0) {
      return res;
    }
    
  
    int pos_s = findFirstPos(inp);
    int neg_e = pos_s - 1; 
    int pos_s_sq = 0;
    int neg_e_sq = 0; 
    
    
    while(pos_s < inp.size() || neg_e >= 0) {
      
      if(pos_s < inp.size() && neg_e >= 0) {
        
        pos_s_sq = sq(inp[pos_s]);
        neg_e_sq = sq(inp[neg_e]);
        
        if(pos_s_sq < neg_e_sq) { 
          res.push_back(pos_s_sq); 
          pos_s++;
        } else {
          res.push_back(neg_e_sq);
          neg_e--;
        }
      } else if(pos_s < inp.size()) {
        
          pos_s_sq = sq(inp[pos_s]);
          res.push_back(pos_s_sq); 
          pos_s++;
      
      } else if(neg_e >= 0) {
          neg_e_sq = sq(inp[neg_e]);
          res.push_back(neg_e_sq);
          neg_e--;
    
      }
    
  }
  
  return res; 
    
  }

  
};

  void printV(vector<int> inp)
  {
    cout<<endl;
    for(int i = 0; i < inp.size(); i++)
    {
      cout<<" "<<inp[i];
    }
    cout<<endl;
    
  }
    
  
  
int main() {
  
  Solution A;
  
  vector<int> test1 = {-4,-2,-1,0,3,5};
  vector<int> test2 = {-4,-2,-1};
  vector<int> test3 = {0, 3, 5};
  
  printV(A.squares_sorted(test1));
  printV(A.squares_sorted(test2));
  printV(A.squares_sorted(test3));
  

  return 0;
}



