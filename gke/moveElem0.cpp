#include <iostream>
#include<vector>

using namespace std;

/* 
Given an array, move the 0s to the front, 
E.g., [3,5,0,4,0] → [0,0,3,5,4]

Assumption: 
- It is ok to modify the relative ordering of non zeros
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
    
   int start = -1; 
    
   for(int j = 0; j < inp.size(); j++) {
     
     if(inp[j] == 0) {
      swap(inp, start + 1, j);
      start++;
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
  vector<int> test2 = {1,1,0};
  vector<int> test3 = {0,1};
  vector<int> test4 = {0,0,1,1,0};

  
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

