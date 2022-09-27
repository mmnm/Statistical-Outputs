using namespace std;

#include <iostream>
#include <vector>
#include<unordered_map>

/* 


{1, 2, 3, 4, 6}, 6
 i

 curE = 1

 sumHash = {
	

 }

*/

class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {

    unordered_map<int, int> sumHash; 
    pair<int, int> sumPair;

    for(int i = 0; i < arr.size(); i++) {
    	int curElem = arr[i];

    	if(sumHash.find(curElem) != sumHash.end()) {

    		sumPair.first = sumHash[curElem];
    		sumPair.second = i;
    		break;
    	}

    	sumHash[targetSum - curElem] = i;
    }

		return sumPair;
  }
};

int main(int argc, char *argv[]) {
  auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: {1, 2, 3, 4, 6}, 6 ->[" << result.first << ", " << result.second << "]" << endl;
  result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: {2, 5, 9, 11}, 11 ->[" << result.first << ", " << result.second << "]" << endl;
}
