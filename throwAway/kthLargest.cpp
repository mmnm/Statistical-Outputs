#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    
    int partition(vector<int>& nums, int s, int e)
    {
        if(s > e)
        {
            return -1;
        }
        int part_elem = nums[s];
        //Throw in bins less than and greater than part_elem
        // 3 4 5 2 1 
        
        int i = s;
        /*
        
        3 2 4 9 1
        i
          j
        */
        for(int j = s + 1; j <= e; j++)
        {
            int curElem = nums[j];
            
            if(curElem < part_elem)
            {
                nums[j] = nums[i + 1];
                nums[i + 1] = curElem;
                i++;
            }
        }
        //Last swap
        nums[s] = nums[i];
        nums[i] = part_elem;
        
        return i;
        
        
    }
    
    int findRank(vector<int>& nums, int s, int e, int rank)
    {
        if(s > e)
        {
            return -1;
        }
        //Rank error handling to be in range

        int part_index = partition(nums, s, e);
        if(part_index == -1)
        {
            cout<<"Bad part_index:"<<endl;
            return -1;
        }
        
        if(part_index == rank)
        {
            return nums[rank];
        }
        else if(part_index > rank)
        {
            //Recur left of part_index
            return findRank(nums, s, part_index - 1, rank);
        }
        else
        {
            return findRank(nums, part_index + 1, e, rank);
        }
        
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        if(k > nums.size() || nums.size() == 0)
        {
            return -1;
        }
        /* 1 2 3 4 5   */
        int k_rank = nums.size() - k;
        
        return findRank(nums, 0, nums.size() - 1, k_rank);
        
    }
};

int main()
{
    std::vector<int> test1 = {3,2,1,5,6,4};
    Solution A;

    cout<<"\n2nd largest: "<<A.findKthLargest(test1, 2);
    cout<<"\n1st largest: "<<A.findKthLargest(test1, 1);
    cout<<"\n3rd largest: "<<A.findKthLargest(test1, 3);
    cout<<"\n4th largest: "<<A.findKthLargest(test1, 4);
    cout<<"\n5th largest: "<<A.findKthLargest(test1, 5);
    cout<<"\n6th largest: "<<A.findKthLargest(test1, 6);
    cout<<"\n7th largest: "<<A.findKthLargest(test1, 7);

    return 0;


}



