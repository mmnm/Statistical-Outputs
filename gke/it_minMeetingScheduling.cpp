// Given a list of meeting star/end times - figure out minimal assignment to conference rooms.

//Input: // 9 - 10   9.30 - 10.30   , 10.30 - 12 
                                                 //i                                               

// []

// //conf
// 1: 10  
// 2: 10.30


// [1,2]
             
//conf1: 10



             
             
             
            // Output: [1, 2, 1]

// {{9,10}, {9,11}}
      
//conference rooms:

//Find the min number of conf rooms
//Allocate conf rooms
//Schedule the free rooms from the list





// Conf room
// 1: Occupied    // 10
// 2:             //1030


// 9- 10, 9.30 - 1030 



//Input: {{9,10}, {9,11}}



#include<iostream>
#include<vector>
#include<unordered_map>





using namespace std;

int start_id = 0;


// Worker cleans up rooms 


void allocate_room(std::vector<int>& res,  std::vector<int> curSet, std::unordered_map<int, int>& rooms, int cur_index)
{
    
    std::unordered_map<int, int>::iterator it = rooms.begin();
    
    
    for(;it != rooms.end(); it++)
    {
        //Find a valid room
        //10end time  < 11
        if(it->second <= curSet[0])
        {
            break;
        }
    }
    
    //New room has to be allocated
    if(it == rooms.end())
    {
        res[cur_index] = start_id;
        rooms[start_id++] = curSet[1];
    }
    else
    {
        res[cur_index] = it->first;
        //Update conf room for new end time
        it->second = curSet[1];
    }
  
}

std::vector<int> meetingAlloc(std::vector<std::vector<int> > times)
{
    
    //Meeting rooms_id : end_time
    
    std::vector<int> res(times.size(), -1);
    
    // if(times.size() == 0)
    // {
    //     return res; 
    // }
    // std::vector<int> res(times.size(), -1);
    
    std::unordered_map<int, int> rooms;
    
    for(int i = 0; i < times.size(); i++)
    {
        
        // {9,10}
        std::vector<int> curTimeSet = times[i];
        allocate_room(res, curTimeSet, rooms, i);
    }
    
    
    return res;
    
}


void printV(std::vector<int> res)
{
    for(int i = 0; i < res.size(); i++)
    {
        
        cout<<res[i]<<endl;
        
    }
    
    cout<<endl;
    
    
}


int main()
{
    
    //  std::vector<std::vector<int> > times = {{9,10}, {9,11}};
    //  std::vector<std::vector<int> > times = {{9,10}, {10,11}};
    //  std::vector<std::vector<int> > times = {{9,10}};
     std::vector<std::vector<int> > times = {{9,11}, {9,10}, {10,12}, {10, 12}, {10, 12}};
                                                              //i
                                        //pool_of_free_rooms
                                        
     //n time, l conf room
     // 
                                                         
   
     

    printV(meetingAlloc(times));


     return 0;
    
    
    
}









     




