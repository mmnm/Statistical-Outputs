using namespace std;

#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = INT_MIN;
    // TODO: Write your code here
    int curKWindowSum = 0;
    for(int i = 0; i < arr.size(); i++) {
      //Fill the first K window 
      if(i < k) {
        curKWindowSum += arr[i];
      } else {
        //Greater than Slide 
        if(i == k) {
          //First slide window
          maxSum = curKWindowSum;
        }
        //Update the curKWindowSum
        curKWindowSum -= arr[i - k];
        curKWindowSum += arr[i];

        if(maxSum < curKWindowSum){ 
          maxSum = curKWindowSum;
        }
      }

    }

    return maxSum;
  }
};

int main() {
  vector<int> test1 = {2,1,5,1,3,2}; 
  vector<int> test2 = {2,3,4,1,5};
  cout<<"Test 1:{2,1,5,1,3,2}, k = 3: "<<MaxSumSubArrayOfSizeK::findMaxSumSubArray(3, test1);
  cout << endl;

   cout<<"Test 2:{2,3,4,1,5}, k = 2: "<<MaxSumSubArrayOfSizeK::findMaxSumSubArray(2, test2);
  cout << endl;

}