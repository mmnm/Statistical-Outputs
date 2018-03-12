#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    void updateSeen(std::unordered_map<char, int>& last_seen_hash, string S)
    {
        for(int i = 0; i < S.size(); i++)
        {
            char curElem = S[i];
            last_seen_hash[curElem] = i;
        }
        
    }
    int findEndPartion(string S, int p_i, std::unordered_map<char, int> last_seen_hash)
    {
        if(S.size() == 0 || p_i < 0) 
        {
            return -1;
        }
        /*ababcba
           i
        */
        //Initialize p_e end window
        int p_e = last_seen_hash[S[p_i]];
        //Now check each char inbetween to update the p_e window
        for(int i = p_i + 1; i < S.size() && i <= p_e - 1; i++)
        {
            int curElem = S[i];
            int loc_p_e = last_seen_hash[curElem];
            
            if(loc_p_e > p_e)
            {
                p_e = loc_p_e;
            }
        }
        return p_e;
    }
    vector<int> partitionLabels(string S) {
        vector<int> answer;
        if(S.size() == 0)
        {
            return answer;
        }
        
        std::unordered_map<char, int> last_seen_hash;
        updateSeen(last_seen_hash, S);
        
        
        int p_i = -1;
        int p_e = -1;
        /* 
        "ababcbaca defegd ehijhklij"
         i       e i            
        */
        for(int i = 0; i < S.size(); ) 
        {
            char curElem = S[i];
            //Find max partition labels
            p_i = i;
            p_e = findEndPartion(S, p_i, last_seen_hash);
            //Found a solution
            
            if(p_e != -1)
            {
                int curPartLen = p_e - p_i + 1;
                answer.push_back(curPartLen);
            }
            cout<<"Why p_e bad?: "<<p_e<<endl;
            i = p_e + 1; 
          cout<<"\nAre we looping for i: "<<i<<endl;
        }
        
        return answer;
        
    }
};

void printVector(vector<int> sol)
{
    cout<<"\nAnswer"<<endl;
    for(int i = 0; i < sol.size(); i++)
    {
        cout<<" "<<sol[i];
    }
    cout<<endl;
}
int main()
{
    string S = "ababcbacadefegdehijhklij";
    Solution A;
    printVector(A.partitionLabels(S));
    return 0;
}