#include <iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<tuple>



/* Debugging Learning

1. Use std:: for all common STL use cases.
2. .push_back doesn't return list and hence don't use it to assign anything 
3. Be careful of edge cases: E.g., 0 - init ; When to delete expired entry? 
At the beginning? Since if you don't delete at the beginning, then you may be
always deleting the current entry (being frequency of 1 which is least)
*/

using namespace std;


class LFUCache {
    
    int _capacity;
    //Tuple: value, frequency, node
    std::unordered_map<int, std::tuple<int, int, std::list<int>::iterator> > hashLRU;
    std::map<int, std::list<int> > hashFreqLists;

    
    
public:
    LFUCache(int capacity) {
        _capacity = capacity;
        
    }
    void deleteMinUsedElem()
    {
      //Find the least freq list to be deleted
        std::map<int, std::list<int> >::iterator  freqListIT = hashFreqLists.begin();
        
        for(; freqListIT != hashFreqLists.end(); freqListIT++)
        {
            if((freqListIT->second).size() > 0)
            {
                break;
            }
        }

      
        //No list found
        if(freqListIT == hashFreqLists.end())
        {
          return;
        }
        //Found atleast a list with one element to delete
        int del_key = (freqListIT->second).front();
        //Delete element from freq List
        (freqListIT->second).pop_front();
        
        //Delete element from hashLRU
        hashLRU.erase(del_key);    
    }
    
    void updateHashListByOne(int key)
    {

        //Error checks
        if(hashLRU.find(key) == hashLRU.end())
        {
            return;
        }
        
        int prev_freq = std::get<1> (hashLRU[key]);
  
        std::list<int>::iterator prevIT = std::get<2> (hashLRU[key]);
        
        if(hashFreqLists.find(prev_freq) == hashFreqLists.end())
        {
            cout<<"Debug this hashFreqLists cur freq key not found"<<endl;
            return;
        }

        //Delete this Node from freq List
   (hashFreqLists[prev_freq]).erase(prevIT);

        //Add this Key to new freq list at the end
        //If this is the first time the list came to existence
        
        if(hashFreqLists.find(prev_freq + 1) == hashFreqLists.end())
        {
            std::list<int> curList;
            curList.push_back(key);
            hashFreqLists[prev_freq + 1] = curList;
        } 
        else
        {
            (hashFreqLists[prev_freq + 1]).push_back(key);
        }

        
        //Update existing frequency 
        std::get<1> (hashLRU[key]) = std::get<1> (hashLRU[key]) + 1;
        
        //Update existing node addr for the Key in hashLRU 
        // The below iterator points to the last element of the list
        std::get<2> (hashLRU[key]) = --((hashFreqLists[prev_freq + 1]).end());
        
    }
    
    int get(int key) {
        
//          if(key in not in hashLRU)
// //     {
// //     return -1;
//     }
    
//     //Update hashFreq corresponding to key
//     //Update hashFreqLists based on key
        
        if(hashLRU.find(key) == hashLRU.end())
        {
            return -1;
        }
        
     
        
        //Update hashFreqLists and get new iterator address
        /*
        Delete elem from old freq list: How ? We have access to iter_node and freq
        Add elem to new fre list: How? We have access to new freq and add it to the end
        
        */
        //Pass hashLRU, new Frequency, old iterator address 
        updateHashListByOne(key);
        
        return std::get<0>(hashLRU[key]) ;
    }
    
   void put(int key, int value) {
     
      if(_capacity == 0)
       {
           return;
       }
        
           //Update list by deleting expired entry
        if((hashLRU.size() >= _capacity) && (hashLRU.find(key) == hashLRU.end()))
        {
         //Find the target element to be deleted and delete it
            deleteMinUsedElem();
        }
     
        //New entry
        if(hashLRU.find(key) == hashLRU.end())
        {
            if(hashFreqLists.find(1) == hashFreqLists.end())
            {
            //Tuple: value, frequency, node
              std::list<int> curList;
              curList.push_back(key);
              hashFreqLists[1] = curList;
            }
            else
            {
              hashFreqLists[1].push_back(key);
            }
              std::tuple<int, int, std::list<int>::iterator> curTupleVal = make_tuple(value, 1, --(hashFreqLists[1].end()));
            hashLRU[key] = curTupleVal;
        }
        else
        {
         //Key already exists
        //Update //Pass hashLRU, new Frequency, old iterator address 
            updateHashListByOne(key);
            //Update value field
            std::get<0> (hashLRU[key]) = value;
        }   
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

// To execute C++, please define "int main()"
int main() {
 
  LFUCache X(0);
  
  // // Test case 1
  // X.put(1,1);
  // X.put(2,2);
  // cout<<X.get(1)<<endl;
  // X.put(3,3);
  // cout<<X.get(2)<<endl;
  // cout<<X.get(3)<<endl;
  // X.put(4,4);
  // cout<<X.get(1)<<endl;
  
  
  X.put(0,0);
  // cout<<X.get(0)<<endl;
  
  
  
  return 0;
}


/* 
Your previous Python 2 content is preserved below:

This is what your interview environment will look like (except in a real interview you will also have audio).

Use the language dropdown near the top right to select the language you would like to use.

You can run code by hitting the 'Run' button, which will appear near the top left once you've selected a language.

There is also a whiteboard you can use for any sketching you need to do. Click on 'Draw' in the bottom center.
 */