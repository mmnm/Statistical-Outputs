#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;




class Interval
{
public:
  int start;
  int end;

  Interval(int s, int e) {
    start = s;
    end = e;
  };
  
};

bool myCompareInt(Interval a, Interval b) {
  return a.start < b.start;
}

class MergeIntervals {

public:
  std::vector<Interval> merge(std::vector<Interval> v) {

    //Sort with start
    std::sort(v.begin(), v.end(), myCompareInt);

    std::vector<Interval> result; 

    if(v.size() <= 1) {
      return v;
    }

    Interval prevVal = v[0];
    for(int i = 1; i < v.size(); i++) {
      Interval curVal = v[i];

      //No overlap
      if(prevVal.end < curVal.start) {
        result.push_back(prevVal);
        prevVal = curVal;
      } else {
        //Overlap case
        prevVal.end = std::max(curVal.end, prevVal.end);
      }
  
      //If curVal is Last elem
      if(i == v.size() - 1) {
        result.push_back(curVal);
      }

    }
    return result;

  }



};

void printVIntervals(std::vector<Interval> v) {
  cout<<endl;
  for(int i = 0; i < v.size(); i++) {
    cout<<v[i].start<<","<<v[i].end<<endl;
  }
  cout<<endl;
}


int main() {
  MergeIntervals A;
  std::vector<Interval> test1 = {{1,3}, {2,5}, {7,9}};
  printVIntervals(test1);
  printVIntervals(A.merge(test1));

  return 0;
}