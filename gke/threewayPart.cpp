/* 
You are given an array of integers and a pivot. Rearrange the array in thefollowing order:[all elements less than pivot, elements equal to pivot, elements greater than pivot]For example,a = [5,2,4,4,6,4,4,3] and pivot = 4 --> result = [3,2,4,4,4,4,5,6].


Algo: 
Left Bubble -> Keep at left, numbers less than pivot 
- Scan left to right (Only from left bubble to right bubble) 
- If encountered less than pivot, swap left and increment j
- If encoutered greater than pivot swap towards end and don't increment j


Debugging/Mistakes
- Found an error that we didn't handle the loop 
, for elem = pivot case
Learning: 
- While testing examples, Don't just walk through,  assuming code is written. 
- Run examples by hand for minimum 1 full test case by going over the code line by line

*/ 


#include <iostream>
#include<vector>

using namespace std;



class Solution {
  
  public: 
  
  void swap(vector<int>& inp, int s, int e) {
   
    int temp = inp[s];
    inp[s] = inp[e]; 
    inp[e] = temp;
    
  }
  void partSort(vector<int>& inp, int pivot) {
    
  
   if(inp.size() == 0) {
     return;
   }
    
    int low_i = -1; 
    int high_j = inp.size();
    
    for(int j = low_i + 1; j <= high_j - 1;) {
      
      
     //Case 1: if elem is pivot, then skip
      if(inp[j] < pivot) {
       
        swap(inp, j, low_i + 1);
        low_i++;
        j++;
      }
      else if(inp[j] > pivot) {
        
       swap(inp, j, high_j - 1);
        high_j--; 
        //Dont increment j in this case, 
        //as the value after swap is still unseen and 
        //needs to be further processed
        
      } else if(inp[j] == pivot) {
        j++;
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
  vector<int> test1 = {5,2,4,4,6,4,4,3};
  vector<int> test2 = {4,4,4,4,4,4,4};
  vector<int> test3 = {3,1,2,2,3,2,4,4};
  vector<int> test4 = {10,5,9,6,7,4,4};
  vector<int> test5 = {1,3,3,1,4,4,4,7,9,7,9};
  vector<int> test6 = {4};
  vector<int> test7 = {9};
  vector<int> test8 = {1};
  vector<int> test9 = {};
  
    
  A.partSort(test1, 4);
  printV(test1);
  
  
  A.partSort(test2, 4);
  printV(test2);
  
  A.partSort(test3, 4);
  printV(test3);
  
  
  A.partSort(test4, 4);
  printV(test4);
  
  A.partSort(test5, 4);
  printV(test5);
  
  A.partSort(test6, 4);
  printV(test6);
  
   A.partSort(test7, 4);
  printV(test7);
  
  A.partSort(test8, 4);
  printV(test8);
  
  A.partSort(test9, 4);
  printV(test9);
  
  A.partSort(test1, 20);
  printV(test1);
  
  A.partSort(test1, 1);
  printV(test1);
    
    
  
  return 0;
}



