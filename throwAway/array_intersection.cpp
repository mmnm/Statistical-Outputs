

 /* Find intersection of two lists
 For example, if the input arrays are:
 arr1[] = {7, 1, 5, 2, 3, 6}
 arr2[] = {3, 8, 6, 20, 7}


 If there are more than one presence in both lists, 
 then output the elements with common count


 1. Create hash for first array
 2. Run through the 2nd array and check if elem in hash





 */


 #include<iostream>
 #include<vector>
 #include<map>

 using namespace std;

 void print_vector(std::vector<int> answer);


 void printHash(std::map<int, int> hashCount)
 {
    std::map<int, int>::iterator it;
   
   for(it = hashCount.begin(); 
       it != hashCount.end(); it++)
   {
     cout<<it->first<<": "<<it->second<<endl;
   }
   
   
 }

 std::vector<int> find_intersection_list(int arr1[],
                     int arr1_len,int arr2[], 
                                 int arr2_len)
 {
    std::vector<int> answer;
   

   
   if(arr1 == NULL)
   {
       return answer;
   }
   
   
   if(arr2 == NULL)
   {
       return answer;
   }


     std::map<int, int> hashCount;
     std::map<int, int>::iterator it;
   
   // cout<<"Yo Arr1 Len: "<<sizeof(arr1)<<endl;
   for(int i = 0; i < arr1_len; i++)
   {
     int curElem = arr1[i];
     
     it = hashCount.find(curElem);
     
     if(it == hashCount.end())
     {
       hashCount[curElem] = 1;
     }
     else
     {
       it->second += 1;
     }
   }
   
   
   
   //Now run through second array to find intersection
   
   for(int i = 0; i < arr2_len; i++)
   {
     int curElem = arr2[i];
     
     it = hashCount.find(curElem);
     
     if(it != hashCount.end())
     {
       if(it->second >= 1)
       {
         answer.push_back(curElem);
         it->second -= 1;
       }
       
     }
     
   }
   
  
   return answer;
     

   
 }

 void print_vector(std::vector<int> answer)
 {
   cout<<"\nAnswer:"<<endl;
   for(int i = 0; i < answer.size(); i++)
   {
     cout<<" "<<answer[i];
   }
   cout<<endl;
   
 }

 int main()
 {
   
   /* Test case 1*/
   int arr1[] = {7, 1, 5, 2, 3, 6};
   
   int arr2[] = {3, 8, 6, 20, 7};
   
   
   
   /* Test case 2*/
   int arr3[] = {7, 1, 5, 7, 9};
   
   int arr4[] = {3, 1, 7, 20, 7};
   

   

   
   
   std::vector<int> answer;
   
   answer = find_intersection_list( arr1, 
             sizeof(arr1)/sizeof(arr1[0]), arr2,
                sizeof(arr2)/sizeof(arr2[0]) );

   print_vector(answer);
   
   
   answer = find_intersection_list( arr3, 
             sizeof(arr3)/sizeof(arr3[0]), arr4,
                sizeof(arr4)/sizeof(arr4[0]) );

   print_vector(answer);
   
   
   
  return 0; 
 }