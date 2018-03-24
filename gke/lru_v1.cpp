#include <iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;




/* Debugging Learnings:

1: .end() returns not the last elem iterator but after that. Use --(x.end()) to get to the prev iterator
2: cap = 2;  put(1,2); put(1,2); put(1,2) // Remember that it doesnt exceed capacity as key(1) is just being replaced

/*

DS

list<int>
list<int>::iterator listIT;
unordered_map<int,  pair<value, node_addr> > hash


1 2 5 

1 5 2


1:
2:
5:


touch(iterator(node))

get(key)
{
    If key is not in hash then return -1
    
    // node_addr = hash[key]->addr
    touch(node_addr)
    return hash->key
}

put(key, value)
{

if key is not in hash
if key is in hash

overflow of hash ->take care of deletion of entry

}

*/





class LRUCache {
    
    unsigned int _capacity;
    std::list<int> listLRU;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator> > hashLRU;
    
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    void touch(std::list<int>::iterator listIT)
    {
        //Error checks
        if(listIT == listLRU.end())
        {
            return;
        }
        
        int key = *(listIT);
        
        if(key <= 0)
        {
            cout<<"What the heck iterator list for touch ??"<<endl;
        }
        listLRU.erase(listIT);
        
        //Add key at the end
        listLRU.push_back(key);
        
        
    }
    
    int get(int key) {
       std::unordered_map<int, std::pair<int, std::list<int>::iterator> >::iterator hashIT;
        
        hashIT = hashLRU.find(key);
        
        
        if(hashIT == hashLRU.end())
        {
            return -1;
        }
        
        //Update node to the end
        touch((hashIT->second).second);
            
        //Update node addr to hashLRU
        (hashIT->second).second = --(listLRU.end());
        
        //Return value
        return (hashIT->second).first;
        
    }
    
    void put(int key, int value) {
        
        
        std::unordered_map<int, std::pair<int, std::list<int>::iterator> >::iterator hashIT;
        
        if(hashLRU.size() >= _capacity)
        {
            //Remove the least used entry
            int remove_key = listLRU.front();
            // Erase entry from list
            listLRU.pop_front();
            
            //Remove entry from hashLRU
            hashLRU.erase(remove_key);
            
        }
        
        
      
        hashIT = hashLRU.find(key);
        //If key exists
        if(hashIT != hashLRU.end())
        {
            //Delete this value's node_addr from list
            listLRU.erase((hashIT->second).second);
        }
       
        //Add this key in list at the end
        listLRU.push_back(key);
  
      
        
        //Store this key, value, addr pair
        hashLRU[key] = std::make_pair(value, --(listLRU.end()));
        
        
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


// To execute C++, please define "int main()"
int main() {

  LRUCache *lru = new LRUCache(2);
  
//   // Test case 1
//   lru->put(2,1);
//   lru->put(2,2);
//   cout<<lru->get(2)<<endl;
//   lru->put(1,1);
//   lru->put(4,1);
//   cout<<lru->get(2)<<endl;
  
  cout<<lru->get(2)<<endl;
  lru->put(2,6);
  cout<<lru->get(1)<<endl;
  lru->put(1,5);
  lru->put(1,2);
  cout<<lru->get(1)<<endl;
  cout<<lru->get(2)<<endl;
  
  return 0;
}


/* 
Your previous Python 2 content is preserved below:


 */