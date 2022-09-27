using namespace std;

#include <iostream>
#include <vector>


class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {

    int s = 0; int e = arr.size() - 1;
		int curSum = 0;
		pair<int, int> result;

		//Error conditions and base cases
		if(arr.size() <= 1) {
			return result;
		}

    curSum = arr[s] + arr[e];
		while(s < e) {
			if(curSum == targetSum) {
        cout<<"Result found target : "<<targetSum<<"::"<<s<<", "<<e<<endl;
				result.first = s;
				result.second = e;
				break;
			} else if(curSum < targetSum) {
				curSum -= arr[s];
        curSum += arr[++s];

			} else if(curSum > targetSum) {
				curSum -= arr[e];
        curSum += arr[--e];
			}
		}
    return result;
  }
};

int main(int argc, char *argv[]) {
  auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
}
