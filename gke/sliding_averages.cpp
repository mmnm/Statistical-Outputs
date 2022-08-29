using namespace std;

#include <iostream>
#include <vector>

class AverageOfSubarrayOfSizeK {
 public:
  static vector<double> findAverages(int K, const vector<int>& arr) { 
    vector<double> result;

    double kSum = 0.0;
    //Create the sliding window 
    for(int i = 0; i < K && i < arr.size(); i++) {
      kSum += arr[i];
    }
    //Push first average
    result.push_back(kSum/K);
    //Slide the window
    for(int i = K; i < arr.size(); i++) {
      //Calculate the next window kSum
      kSum -= arr[i-K];
      //Add new sliding elem 
      kSum += arr[i];
      result.push_back(kSum/K);
    }

    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<double> result = AverageOfSubarrayOfSizeK::findAverages(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
  cout << "Averages of subarrays of size K: ";
  for (double d : result) {
    cout << d << " ";
  }
  cout << endl;
}
