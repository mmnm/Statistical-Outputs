/* 

Implement decodeFind which takes badEncStr and still returns 
valid encoded int

decode()
Input :
kljJJ324hjkS   - 848662

decodeFind()
Input
kljjj324hjkS  - 848662


Debug points:

1. 
Try to use the below lib functions. It saves time

toupper(c))
tolower(c)
isdigit(c)

2. Wasted a lot of time fixing the below shit

//Lower case conversion didnt work as expected
E.g. 

//'s' as input
toupper(char test){
  test = test - '0';
  test -= 32;
  return test +'0';

}
This expected 's' to become 'S' but had issues
Correct way:
touuper(char test) 
{
  char test = (int)test; //Converts to int ascii rep
  test -=32;
  test = (char) test

}






*/


#include<iostream>
#include<map>
#include<string>
#include<vector>


using namespace std;

void initialize_hash(std::map<string, int> &encodedHash)
{
 
  encodedHash["kljJJ324hjkS"] = 848662;
  
}


int decode(std::map<string, int> encodedHash, string str)
{
   
  std::map<string, int>::iterator it;
  
  it = encodedHash.find(str);
  
  if(it != encodedHash.end())
  {
    return encodedHash[str];
  }
  
  return -1;
  
}

bool isNumber(char test)
{
  test = test - '0';
  if(test >= 0 && test <= 9)
  {
      return true;
  }
  return false;
  
}

char swapCase(char test)
{
  // cout<<"Original: "<<test<<" ascii: "<<int(test);
  
  char tester = (int)(test);
  // cout<<"\nTester: "<<tester<<endl;

  
  if(tester >= 97 && tester <= 122)
  {
    tester -= 32;
  }
  else 
  {
    tester += 32;
  }
  

  test = (char)(tester);
  // cout<<" Swapped: "<<test<<endl;
  return test;
  
}


void printVector(std::vector<string> &allPerms)
{
  for(int i = 0; i < allPerms.size(); i++)
  {
    cout<<"Current vector" <<allPerms[i]<<endl;
  }
}

void findAllStringPerms(std::vector<string> &allPerms,
                      string str, int cursor)
{
  
 if(str.length() == 0 || cursor >= str.length())
 {
   return;
 }
  
 
  
 
  for(int i = cursor; i < str.length(); i++)
  {
    char curElem = str[i];
    
    //Skip if number
    if(isNumber(curElem)) 
    {
      continue;
    }
    
    //Swap uppercase to lower case and vice-versa
    
    char swapped = swapCase(curElem);
    // cout<<"Orig Elem: "<<curElem<<" and swapped: "<<swapped<<endl;
    str[i] = swapped;
    // cout<<"Current Elem to be pushed: "<<str<<endl;
    allPerms.push_back(str);
    //Find remaining combinations 
    findAllStringPerms(allPerms, str, i + 1);
    
    //Backtrack
    str[i] = curElem;
  
  }
  
}

int decodeFind(std::map<string, int> encodedHash, 
               string str)
{
  
 int retVal =  decode(encodedHash, str);
  
  if(retVal != -1)
  {
    return retVal;
  }
  
  //Find all permutations of mis-spelled permutations
  
  
  std::vector<string> allPerms;
    // cout<<"Vector Size: :"<< allPerms.size()<<endl;
  findAllStringPerms(allPerms, str, 0);
  
  printVector(allPerms);
  
  for(int i = 0; i < allPerms.size(); i++)
  {
    retVal = decode(encodedHash, allPerms[i]);
    if(retVal == -1)
    {
      continue;
    }
    else
    {
        return retVal;
    }
  }
  
  return retVal;
}

int main()
{
  std::map<string, int> encodedHash;
  
  initialize_hash(encodedHash);
  
  
  cout<<decodeFind(encodedHash, "kljJJ324hjkS")<<endl;
  cout<<decodeFind(encodedHash, "kljjj324hjkS")<<endl;
  
  
 return 0; 
}