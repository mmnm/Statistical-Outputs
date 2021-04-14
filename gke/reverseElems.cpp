#include <iostream>
#include<vector>

using namespace std;

/* 
Given an array, reverse the order of its elements.For example, [3,5,2,5,2,3,9] → [9,3,2,5,2,5,3]
Contraints: 
- Modify same array 
- Usual Error handling 

Sol: 
- Traverse from both ends and swap elems from front to back
- Stop at middle



Test cases: 

[3,5,2,5,2,3,9] → [9,3,2,5,2,5,3]
[]
[1,2,3]
[1,2,3,4]
[1]


{4,3,2, 1};
     s  
  e

*/

class Solution {
  
  public: 
  
  void swap(vector<int>& inp, int s, int e) {
   
    int temp = inp[s];
    inp[s] = inp[e]; 
    inp[e] = temp;
    
  }
  void reverseElems(vector<int>& inp) {
    
   if(inp.size() == 0) {
     return;
   }
    
    int start = 0;
    int end = inp.size() - 1;
    
    for(; start < end; start++, end--) {
     
      swap(inp, start, end);
        
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
  vector<int> test1 = {1,2,3};
  vector<int> test2 = {1,2};
  vector<int> test3 = {1};
  vector<int> test4 = {};
  
  
  A.reverseElems(test1);
  printV(test1);
  
  
  A.reverseElems(test2);
  printV(test2);
  
  A.reverseElems(test3);
  printV(test3);
  
  A.reverseElems(test4);
  printV(test4);
 
  return 0;
}

