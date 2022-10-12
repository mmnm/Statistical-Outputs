#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/* Merge overlapping intervals */ 

class Interval {

public: 
	int start;
	int end;

	Interval(int s, int e) {
		start = s;
		end = e;
	}

};

bool compareStart(Interval a, Interval b) {
	return a.start < b.start;
}

class MergeIntervals {
public:
	static vector<Interval> mergeOverlaps(vector<Interval> &inp) {
		vector<Interval> res;
		if(inp.size() <= 1) {
			return inp;
		}
		// We need to sort the interval based on the start 
		std::sort(inp.begin(), inp.end(), compareStart);

		//Merge overlapping intervals 
		Interval prevElem = inp[0];

		for(int j = 1; j < inp.size(); j++) {
			Interval curElem = inp[j];
			//If merge not possible
			if(prevElem.end < curElem.start) {
				res.push_back(prevElem);
				prevElem = curElem;
 
			} else {
				//Merge possible, hence merge it
				prevElem.end = max(prevElem.end, curElem.end);
			}
			//Last elem case
			if(j == inp.size() - 1) {
				res.push_back(prevElem);
			}

		}

		return res;
	}
};


int main() {
	vector<Interval> input1 = {{7, 9}, {2, 5}, {1, 3}};
	vector<Interval> input2 = {{6, 7}, {2, 4}, {5, 9}};
	vector<Interval> input3 = {{1, 4}, {2, 6}, {3, 5}};


	cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::mergeOverlaps(input1)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::mergeOverlaps(input2)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::mergeOverlaps(input3)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;


	return 0;
}