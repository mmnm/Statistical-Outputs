#include <iostream>
#include<vector>

using namespace std;

/* 


Algo: 
- 
Quick sort 

4,1,2,3,5
        j
        i


*/

class Solution {
  
  public: 
  
  void swap(vector<int>& inp, int s, int e) {
   
    int temp = inp[s];
    inp[s] = inp[e]; 
    inp[e] = temp;
    
  }
  
  int partition(vector<int>& inp, int s, int e) {
    
   if(inp.size() == 0 || s >= e) {
     return -1;
   }
    
   //Algo: Move all elems less than part elem to left -> part
    
    //Choose random partition
    int r_index = rand() % (e - s + 1) + s;
    
    if (r_index > e || r_index <  s) {
      
      cout<< "what the hell rand"<<endl;
      r_index = s;
      
    }
    swap(inp, r_index, s);
    
    
    int part_elem = inp[s];
    
    int i = s;
    
    for(int j = s + 1; j <= e; j++) {
     
      if(inp[j] < part_elem) {
        
       swap(inp, j, i + 1); 
       i++;
      }
      
    }
    
    swap(inp, s, i);
    return i;
    
    
  }
  
  void qSortUtil(vector<int>& inp, int s, int e) {
    
   if(inp.size() == 0 || s >= e) {
     return;
   }
  
    int r = partition(inp, s, e); 
    if( r == -1) {
      return;
    }
    
    qSortUtil(inp, s, r - 1); 
    qSortUtil(inp, r + 1, e);
    
  }
  
  
  void qSort(vector<int>& inp) {
    
   if(inp.size() == 0) {
     return;
   }
    
   qSortUtil(inp, 0, inp.size() - 1);
    
  } //end function
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
  vector<int> test1 = {1,5,4,3,2};
  vector<int> test2 = {5,4,3,2,1};
  vector<int> test3 = {1,2,3,4,5};
  vector<int> test4 = {6,1,2,3,4,5};
  vector<int> test5 = {};
  vector<int> test6 = {1};
  vector<int> test7 = {1,2};
  vector<int> test8 = {2,1};
  
  A.qSort(test1);
  printV(test1);
  
  A.qSort(test2);
  printV(test2);
  
  
  A.qSort(test3);
  printV(test3);
  
  A.qSort(test4);
  printV(test4);
  
  A.qSort(test5);
  printV(test5);
  
  A.qSort(test6);
  printV(test6);
  
  A.qSort(test7);
  printV(test7);
  
  A.qSort(test8);
  printV(test8);

  
 
 
  return 0;
}



