/* Word split from dictionary. Return if not possible

iamsamsung


*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>


using namespace std;

bool is_in_dict(std::string test)
{
  std::unordered_map<std::string, bool> dict;
  
  dict["i"] = true;
  dict["am"] = true;
  dict["a"] = true;
  dict["sam"] = true;
  dict["sung"] = true;
  
  std::unordered_map
    <std::string, bool>::iterator it;
  it = dict.find(test);

  if(it != dict.end())
  {
    return true;
  }
  else 
  {
    return false;
  }
}

//input: "iamsamsung"
//output: valid split words vector
std::vector<std::string> 
word_splitter(std::string input)
{
  
  std::vector<std::string> answer; 
  
  if(input.length() == 0) 
  {
    return answer;
  }
  
  for(int i = 0; i < input.size(); i++)
  {
    //prefix 0... i; Eg: i
    std::string prefix = 
      input.substr(0, i + 1);
    
    if(is_in_dict(prefix))
    {
      //suffix: i + 1 .. end Eg, amsamsung
      std::string suffix = 
        input.substr(i + 1);
      
      if(suffix.length() == 0)
      {
        //Found answer
        answer.push_back(prefix);
        return answer;
      }
      
      std::vector<std::string> ret = 
        word_splitter(suffix);
      
      if(ret.size() != 0)
      {
        //Found answer
        answer.push_back(prefix);
        answer.insert(answer.end(),
                      ret.begin(),
                      ret.end());
        return answer;

      }
    }
  }
  
  return answer;
  
}

void printVector(std::vector<std::string> v)
{
 
  cout<<endl;
  
  if(v.size() == 0)
  {
    cout<<"No valid split possible"<<endl;
  }
  
  for(int i = 0; i < v.size(); i++)
  {
    cout<<v[i]<<endl;
  }
    
}

int main()
{
 
  //Test case 1
  std::string input = "iamsamsung";
  
  //Test case 2
  std::string input2 = "isungsaamm";
  
  std::vector<std::string> answer; 
  
  answer = word_splitter(input);
  printVector(answer);
  
  answer = word_splitter(input2);
  printVector(answer);
  
  return 0;

}