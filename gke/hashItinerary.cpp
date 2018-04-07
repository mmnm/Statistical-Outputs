#include <iostream>
#include<unordered_map>
#include<vector>





using namespace std;


//Input: vector<vector<string> > passes
// Output: vector<string>

// {"SFO", "BAL"},        {""} ...
     // i
std::unordered_map<string, string> constructHash(std::vector<std::vector<string> > input)
{
  
 
  std::unordered_map<string, string> hash;
  
  for(int i = 0; i < input.size(); i++)
  {
    
    std::vector<string> curElem = input[i];
    
    hash[curElem[0]] = curElem[1];
    
  }
  
  return hash;  

  
}


string findStart(  std::unordered_map<string, string> hashInput)
{
  
  //Error checks
  
  
  
  
  std::unordered_map<string, int> revHash;
    
  std::unordered_map<string, int>::iterator revIt;
  
  std::unordered_map<string, string>::iterator it = hashInput.begin();
  
  
  for(; it != hashInput.end(); it++)
  { 
    if(revHash.find(it->first) == revHash.end()) {
      revHash[it->first] = 0; 
    }
    revHash[it->second] = 1;
  }
  


  for(revIt = revHash.begin(); revIt != revHash.end(); revIt++)
  {
    // cout<<revIt->first<<","<<revIt->second<<endl;
    
    if(revIt->second == 0)
    {
      return revIt->first;
    }
  
 
  }
  

  //Some error
  return "";

}
  

std::vector<string> makeItin(std::vector<std::vector<string> > input)
{
  
  std::vector<string> answer;
//Error checks
 if(input.size() <= 0)
 {
   return answer;
 }
  
  //Construct hash for the input
  
  std::unordered_map<string, string> hashInput = constructHash(input);
  
  string start_elem = findStart(hashInput);
  
  if(start_elem == "")
  {
    cout<<"Debug this start_elem not found";
    return answer;
    
  }
  
  //Construct answer
  
  /*
  
  JFK -> LAS
  BOS -> SFO
  SFO -> JFK
  
  
  s_e = LAS
  
  a: BOS, SFO, JFK, LAS
  
  
  
  
  
  */
  
  
  answer.push_back(start_elem);
  
  while(hashInput.find(start_elem) != hashInput.end())
  {
   start_elem = hashInput[start_elem]; 
  
    answer.push_back(start_elem);
  }
  
return answer;
  
}



void printVect( std::vector<string> result)
  
{
 
  for(int i = 0; i < result.size(); i++)
  {
   
    cout<<" " << result[i];
    
  }
  
  
}

// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  
  
  
  std::vector<std::vector<string> > input;
  
  std::vector<string> cur;
  
  cur.push_back("JFK");
  cur.push_back("LAS");
  
  
  
  std::vector<string> cur1;
  
  cur1.push_back("BOS");
  cur1.push_back("SFO");
  
  
  
  
  std::vector<string> cur2;
  
  cur2.push_back("SFO");
  cur2.push_back("JFK");

  
  input.push_back(cur1);
  input.push_back(cur2);
  input.push_back(cur);
 
  
  
  std::vector<string> result = makeItin(input);
  
  printVect(result);
  
  
  
  
  return 0;
}



/*
Input:

  JFK - LAS
  SFO - BOS
  SFO - JFK
  JFK - SFO
  SFO - LAS
  
  
  
  
  JFK
  
      <--- 
        LAS
             
        <--
        JFK
          
         
         
  
  

Output:
  BOS -> SFO -> JFK -> SFO -> LAS
  LAS -> JFK -> SFO -> BOS
  
  {
    JFK: LAS,
    BOS: SFO,
    SFO: JFK
  }
  
  BOS -> 
  
  
  4
  
  
  BOS SFO JFK LAS
  
  
  
  
  
  
  JFK -> LAS
  
  s - BOS -> SFO
  
  SFO -> JFK
  
  
  
  
  //Graph
  
  

*/

