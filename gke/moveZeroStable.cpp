#include <iostream>
#include<vector>

using namespace std;

/* 
Given an array, move the 0s to the front, 
E.g., [3,5,0,4,0] → [0,0,3,5,4]
[0,0,3,5,4] 
       i
   j
 
Assumption: 
- Do not modify the relative ordering of non zeros
- We need to do this in O(1) space


Tests 
1,0
1,1,0
1,1,0,0
0,0,1

Algo: 
- Swap elems to front when we enconter 0

*/

class Solution {
  
  public: 
  
  void swap(vector<int>& inp, int s, int e) {
   
    int temp = inp[s];
    inp[s] = inp[e]; 
    inp[e] = temp;
    
  }
  void moverZero(vector<int>& inp) {
    
   if(inp.size() == 0) {
     return;
   }
   
  // If we see non zero then we copy, else skip 
    
    int i = inp.size(); 
    
    for(int j = inp.size() - 1; j >= 0; j--) {
      
      if(inp[j] != 0) {
       
        swap(inp, j, i - 1);
        i--;
      }
      
    }

  }

  
};

void printV(vector<int> inp) {
  
 cout<<endl;
  for(int i = 0; i < inp.size(); i++) {
    
    cout<<" "<<inp[i];
    
  }
  cout<<endl;
}

int main() {
  
  Solution A;
  vector<int> test1 = {1,0};
  vector<int> test2 = {1,2,0};
  vector<int> test3 = {0,1};
  vector<int> test4 = {0,0,1,2,0};

  
  A.moverZero(test1);
  printV(test1);
  
  
  A.moverZero(test2);
  printV(test2);
  
  A.moverZero(test3);
  printV(test3);
  
  A.moverZero(test4);
  printV(test4);
 
  return 0;
}


