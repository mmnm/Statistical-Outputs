/* E.g, 

  y ouareamean
  T(n) = T(1) + T(n - 1)
  p
pre 0...i
suf i+1.. end



dict: you, are, area, mean, me

*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string>



using namespace std;




class Solution {
  
 public:
  
  bool isInDict(string word, 
                std::unordered_set<string>& hashSet)
  {
   
    if(hashSet.find(word) != hashSet.end())
    {
      return true;
    }
    
    else
    {
      return false;
    }
    
  }
  void initDict(std::unordered_set<string>& hashSet,
               vector<string>  wordDict) 
  {
    
    for(int i = 0; i < wordDict.size(); i++)
    {
     
      hashSet.insert(wordDict[i]);
    }
    
  }
  
  bool wordBreakUtil(string s, 
                     std::unordered_set<string> hash, std::unordered_map<string, bool>& wordSplitHash) {
  
  if(wordSplitHash.find(s) != wordSplitHash.end())
  {
    return wordSplitHash[s];
  }
    
   if(s.size() == 0)
   {
     return false;
   }
    
    for(int i = 0; i < s.size(); i++)
    {
      // iam -> i
      // 0
      //man
      string prefix = s.substr(0, i + 1); 
      
      if(isInDict(prefix, hash))
      {
        //Check if suffix returns valid break
        string suffix = s.substr(i + 1);
        
        if(suffix.size() == 0 || 
           wordBreakUtil(suffix, hash, wordSplitHash))
        {
          wordSplitHash[s] = true;
          return true;
        }
        
      }
      
    }
    
    wordSplitHash[s] = false;
    return false;
    
  }
  
  bool wordBreak(string s, vector<string> & wordDict) {
    
    
    std::unordered_set<string> hashSet;
    std::unordered_map<string, bool> wordSplitHash;
    initDict(hashSet, wordDict);
  
    return wordBreakUtil(s, hashSet, wordSplitHash);
  
  }

  
  
};



int main()
{
  
  Solution moduleA;
  
//Test case 1
 vector<string> tv1;
  tv1.push_back("you");
  tv1.push_back("are");
  tv1.push_back("mean");
  tv1.push_back("area");
  
  cout<<"Test case: "<<"youaremean"
    <<" ::split? true::";
    cout<<moduleA.wordBreak("youaremean", tv1)<<endl;
  
  
   cout<<"Test case: "<<"your"
    <<" ::split? true::";
    cout<<moduleA.wordBreak("your", tv1)<<endl;
  
  cout<<"Test case: "<<"you"
    <<" ::split? true::";
    cout<<moduleA.wordBreak("you", tv1)<<endl;
  
 return 0; 
}