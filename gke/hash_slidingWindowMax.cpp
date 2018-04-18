#include <iostream>
#include<vector>
#include<sstream>
#include<map>
using namespace std;


std::vector<int> sliding_window_max(std::vector<int> v, int k)
{
 
  std::vector<int> res;
  
  if(k > v.size())
  {
    return res;
  }
  
  //Create slide max for first window

  /* 
  
  Create sliding ordered hash
  
  Keep updating the slide and find new max (highest value of hash)
  
  */

  std::map<int, int> slideHash;
  std::map<int, int>::reverse_iterator rit;
  
  
  //Create for first slide
  for(int i = 0; i < k; i++)
  {
    int curElem = v[i];
    if(slideHash.find(curElem) == slideHash.end())
    {
      slideHash[curElem] = 1;
    }
    else
    {
      slideHash[curElem] += 1;
    }
  }
  
  rit = slideHash.rbegin();
  
  if(rit == slideHash.rend()) {cout<<"Debug this"<<endl; return res;}
  
  res.push_back(rit->first);
  
  //Find max for remaining k windows
  
  for(int i = k; i < v.size(); i++)
  {
    int del_elem = v[i - k];
    int curElem = v[i];
    
    //Erase from hash
    slideHash[del_elem]--;
    
    //Add curElem to hash
    if(slideHash.find(curElem) == slideHash.end())
    {
      slideHash[curElem] = 1;
    }
    else
    {
      slideHash[curElem] += 1;
    }
    
    if(slideHash[del_elem] <= 0)
    {
      slideHash.erase(del_elem);
    }
    
    rit = slideHash.rbegin();
    
      
  if(rit == slideHash.rend()) {cout<<"Debug this"<<endl; return res;}
  
  res.push_back(rit->first);
    
  }
  
  return res;
  
  
}
  
    
void printV(std::vector<int> v)
{
  cout<<endl;
  for(int i = 0; i < v.size(); i++)
  {
   
    cout<<" " <<v[i];
    
  }
  
}
  


int main()
{
  

  
  std::vector<int> test1 = {1, 2, 3, 1, 4, 5, 2, 3, 6};
  std::vector<int> result1 = sliding_window_max(test1, 3);
  //Should print 3 3 4 5 5 5 6
  printV(result1);
  
  
  std::vector<int> test2 = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
  std::vector<int> result2 = sliding_window_max(test2, 4);
  //Should print 10 10 10 15 15 90 90
  printV(result2);
  
  
  
  return 0;
  
  
}
