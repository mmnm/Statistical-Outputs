#include<iostream>
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include<cmath>

using namespace std;


class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};





void printMedian(int *arr, int len)
{
	if(arr == NULL)
	{
		return;
	}
	cout<<"Running median stream is: "<<endl;



	typedef std::function<bool(int, int)> comp_type;

	std::priority_queue<int> max_pq;
	std::priority_queue<int, vector<int>, std::greater<int> > min_pq;

				

	/*
		check the first two elements and insert the smaller in max_pq and bigger in min_pq
		
		Print median
		
		For every new in-coming number
			if(number > min_pq.top()) 
				//Put it in min_pq
				//else put it in max_pq

		balance 
			if |queue1| and |queue2| differ by more than 1, then pop out from higher and push it to lower
		print median
			if equal size , then median is top1 + top2 / 2
			else median is top of one with big size


	*/

	cout<<"\n"<<arr[0];


	for(int i = 1; i < len; i++)
	{
		//cout<<"\nValue is : "<<arr[i]<<endl;

		if(i == 1)	
		{
			if(arr[i - 1] > arr[i])
			{
				int cur = arr[i];
				int prev = arr[i - 1];

				max_pq.push(arr[i]);
				min_pq.push(arr[i - 1]);
	
			}
			else 
			{
				max_pq.push(arr[i - 1]);
				min_pq.push(arr[i]);
			}	
				
			if(max_pq.size() && min_pq.size())
			{
				cout<<"\n"<<(max_pq.top() + min_pq.top()) / 2;
			}
			else
			{
				cout<<"Debug this"<<endl;
			}
			continue;
		}
		else 
		{
			if(arr[i] > min_pq.top())
			{
				min_pq.push(arr[i]);
			}
			else 
			{
				max_pq.push(arr[i]);
			}
		}
		//Now balance the pqs if required

		int min_pq_size = min_pq.size();
		int max_pq_size = max_pq.size();
	
		if(abs(min_pq_size - max_pq_size) > 1)
		{
			//Balancing required
			if(min_pq_size > max_pq_size)
			{
				//pop from min pq and insert to max pq
				int pop_elem = min_pq.top();
				min_pq.pop();
				max_pq.push(pop_elem);
			}
			else 
			{
				//pop from min pq and insert to max pq
				int pop_elem = max_pq.top();
				max_pq.pop();
				min_pq.push(pop_elem);
			}
		}
		
		//Print median
		if(min_pq.size() == max_pq.size())
		{
			cout<<"\n"<<(max_pq.top() + min_pq.top()) / 2;
		}
		else if(min_pq.size() > max_pq.size())
		{
			cout<<"\n"<<min_pq.top();
		}
		else
		{
			cout<<"\n"<<max_pq.top();
		}
		
				
	}

	
	cout<<endl;		


}
	






int main()
{
	int arr1[] =  {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
	printMedian(arr1, sizeof(arr1)/sizeof(arr1[0]));
	return 0;

}




