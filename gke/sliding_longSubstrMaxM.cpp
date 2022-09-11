

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/* 

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".


Edge cases and assumptions: 
1. K > size(Array) : Output: size(Array)
2. K == 1; Output: 1 (Any elem)
3. K == 0; Output: 0
4. Return only the length of one valid answer


Keep track of max_substring and update at below steps 

1. Keep a sliding window and add one element at a time 
2. Expand the window by adding one elem from right
3. Keep a track of unique elements in a unordered map and update appropriately
4. If the hash has more elems than K, then delete elems from left 


Trace example Input: String="araaci", K=1
     
hash {
i : 1

}
m_s = 2
m_e = 3
curElem = a
String="araaci", K=1
             s
              e

*/



class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    unordered_map<char, int> hashCount;
    unordered_map<char, int>::iterator it;
    int s = 0;
    int m_s = 0;
    int m_e = 0;

    //Edge cases
    if(k == 0) {
      return k;
    }

    for(int e = 0; e < str.size(); e++){
      char curElem = str[e];

 
      //Update hash and current window
      if(hashCount.find(curElem) != hashCount.end()) {
        hashCount[curElem] = hashCount[curElem] + 1;
      } else {
        hashCount[curElem] = 1;
      }

      //Max K size reached, update the window
      while (hashCount.size() > k) {
        if(s >= e || hashCount.size() <= k) {
          break;
        }
        //Update hash 
        char del_elem = str[s];
        hashCount[del_elem] = hashCount[del_elem] - 1;
        if(hashCount[del_elem] == 0) {
          hashCount.erase(del_elem);
        }
        s++;
      }

      //Found an answer, update max_windows
      if(hashCount.size() <= k) {

        if((m_e - m_s) < (e - s)){
          m_s = s;
          m_e = e;
        }
      }
    }

    return m_e - m_s + 1;
  }
};


int main() 
{
  LongestSubstringKDistinct A;
  cout<<A.findLength("araaci", 2)<<" Expected araaci, 2 : 4"<<endl;
  cout<<A.findLength("araaci", 1)<<" Expected:araaci, 1: 2"<<endl;
  cout<<A.findLength("cbbebi", 3)<<" Expected: cbbebi, 3: 5"<<endl;
  return 0;
}
