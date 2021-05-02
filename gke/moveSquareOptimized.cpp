
#include <iostream>
#include<vector>

using namespace std;



/* 
Given a sorted array in non-decreasing order, return an array of squares of each number, also in non-decreasing order. For example:

[-4,-2,-1,0,3,5] -> [0,1,4,9,16,25]
  n
              p

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
  
  /*
  [-4,-2,-1,0,3,5] -> [0,1,4,9,16,25]
                       r_e
            s
            e
  
  s_p = 0
  e_p = 0
              
              
              [0,1,4,9,16,25]
              
  */
  
  vector<int> squares_sorted(vector<int> inp) {
    
    vector<int> res = inp; 
    
    //Ago: 1. Have s and e counters
    // 2. Keep pushing largest elems to the front
    // 3. Adjust s and e accordingly 
    
    
    int s = 0; 
    int e = inp.size() - 1; 
    int r_e = res.size() - 1; 
    
    for(; s <= e; ) {
      
      if(s == e) {
       
       res[r_e--] = inp[s] * inp[s];
        s++;
      } else {
        
        int s_p = inp[s] * inp[s];
        int e_p = inp[e] * inp[e];
        
        if(s_p >= e_p) {
         
          res[r_e--] = s_p;
          s++;
        } else {
          
          res[r_e--] = e_p;
          e--;
        }
              
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




