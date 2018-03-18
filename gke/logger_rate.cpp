#include <iostream>
#include<queue>

using namespace std;

/* 

Design and implement a rate limiter

It should limit function calls within a period

Example Allow only 20 calls per 5 minutes and drop others

counter = 0;

#define ALLOWED 3
#define MAX_TS 10

bool rate_limit(int ts)
{

//Have a queue of timestamps
//Update counter with removal of expired entries
//Return true if counter < MAX_ALLOWED

}


cout<<rate_limit(1)<<endl;     // true
cout<<rate_limit(2)<<endl;     //true
cout<<rate_limit(4)<<endl;    //true
cout<<rate_limit(8)<<endl;    //false
cout<<rate_limit(11)<<endl;   //true              //counter = 3
cout<<rate_limit(12)<<endl;   //true              //counter = 3
cout<<rate_limit(13)<<endl;   //false             //counter = 3
        


*/

#define ALLOWED 3
#define MAX_TS 10


class RateLimit
{
  int counter;
  std::queue<int> tsQueue;
  
  void updateExpired(int ts)
  {
    int expired_ts = ts - MAX_TS;
    
    
    while(!(tsQueue.empty()))
    {
      int cur_ts = tsQueue.front();
      
      if(expired_ts >= cur_ts)
      {
        // cout<<"Counter is fucked: "<<counter<<endl;
        tsQueue.pop();
        counter--;
      }
      else 
      {
        break;
      }
      
    }
          
    
  }
  
 public:
  
  RateLimit()
  {
    counter = 0;
  }
  
  bool rate_limit(int ts)
  {
    updateExpired(ts);
    // cout<<"TS is: "<<ts<<endl;
    // cout<<"Counter is: "<<counter<<endl;
    if(counter < ALLOWED)
    {
      counter++;
      tsQueue.push(ts);
      return true;
    }
    else
    {
      return false;
    }
    
  }
            
          
};


int main()
{
   
  RateLimit A;
  
  
cout<<A.rate_limit(1)<<endl;     // 1
cout<<A.rate_limit(2)<<endl;     //1
cout<<A.rate_limit(4)<<endl;    //1
cout<<A.rate_limit(8)<<endl;    //0
cout<<A.rate_limit(11)<<endl;   //1              //counter = 3
cout<<A.rate_limit(12)<<endl;   //1              //counter = 3
cout<<A.rate_limit(13)<<endl;   //0             //counter = 3
cout<<A.rate_limit(20)<<endl;   //1             //counter = 3
  return 0;
  
  
  
}
          






