/* 

Given various intervals like below and a test number return true if the test nunber belongs to any interval

This function will be called again and again. No extra space is allowed


E,g 1:

{{1,3}, {9, 11}, {5,10}, {2,4} } 
, 3 
Output: true
,4
Output: true
,11
Output: true


Idea 1:

Step 1: Sort the interval and merge overlapping intervals


Step 2: Perform Binary search based on start_key <=  test, 
if start_key_found == -1 then return false
if start_key_found == test return true
if(end_key_found >= test return true

Else for all other use case return false




*/





#include<iostream>
#include<vector>


using namespace std;


void printIntervals(std::vector<std::vector<int> > elems);

bool myElemSort(std::vector<int> elem1, std::vector<int> elem2)
{

	return (elem1[0] < elem2[0]);
}

std::vector<int> mergeElem(std::vector<int> elem1, std::vector<int> elem2)
{

	std::vector<int> curElem;

	curElem.push_back(min(elem1[0], elem2[0]));
	curElem.push_back(max(elem1[1], elem2[1]));
	return curElem;

}

std::vector<std::vector<int> > mergeIntervals(std::vector<std::vector<int> > 
						elems)
{
	if(elems.size() <= 1)
	{
		return elems;
	}
	std::vector<std::vector<int> > res;

	std::sort(elems.begin(), elems.end(), myElemSort);


	std::vector<int> prevElem = elems[0];

	for(int i = 1; i < elems.size(); i++)
	{

		std::vector<int> curElem = elems[i];


		//Check if mergeable
		if(prevElem[1] >= curElem[0])
		{
			//Merge elems
			std::vector<int> curP;
			curP.push_back(prevElem[0]);
			curP.push_back(curElem[1]);
			prevElem = curP;
			//prevElem = mergeElem(prevElem, curElem);
		}
		else
		{
			//Push Prev and allocate
			res.push_back(prevElem);
			prevElem = curElem;
		}

		if(i == elems.size() - 1)
		{
			res.push_back(prevElem);

		}
	}


	return res;
}


std::vector<int>  findStartBS(std::vector<std::vector<int> > elems, 
	int start, int end, int value)
{

	std::vector<int> res;
	if(start > end)
	{
//		cout<<"Why we are here?"<<endl;
		return res;
	}


	int mid = (start + end) / 2;


	int mid_elem = elems[mid][0];

	if(mid_elem == value)
	{
		return elems[mid];

	}
	else if(mid_elem < value)
	{
		if((mid == elems.size() - 1) || (elems[mid + 1][0] > value))
		{
			return elems[mid];
		}
		else 
		{
			return findStartBS(elems, mid + 1, end, value);
		}
	}
	else if(mid_elem > value)
	{
		return findStartBS(elems, start, mid - 1, value);
	}

	return res;


}


bool isInIntervalUtil(std::vector<std::vector<int> > elems, int value)
{
	std::vector<int> curMatchInt = findStartBS(elems, 0, elems.size() - 1,
					value);

	
	if(curMatchInt.size() == 0)
	{
//		cout<<"CurMatchInterval not found"<<endl;
		return false;
	}
	
//	cout<<"CurMatchInt:: "<<curMatchInt[0]<<","<<curMatchInt[1]<<endl;

	if((curMatchInt[0] <= value) && (curMatchInt[1] >= value))
	{
		return true;
	}

	return false;
} 


bool isInInterval(std::vector<std::vector<int> > elems, int value)
{
	

	std::vector<std::vector<int> > mElems = mergeIntervals(elems);
//	cout<<"Sorted Interval::"<<endl;
	printIntervals(mElems);

	return isInIntervalUtil(mElems, value);
}
	
void printIntervals(std::vector<std::vector<int> > elems)
{
	for(int i = 0; i < elems.size(); i++)
	{
		cout<<elems[i][0]<<","<<elems[i][1]<<" ";
	}

	cout<<endl;
}



int main()
{
	std::vector<std::vector<int> > test1 = {{2,3}, {9, 11}, {6,10}, {2,4}};

	printIntervals(test1);


	cout<<"\n*****IsIntInterval ? 1:  "<<isInInterval(test1, 1)<<endl;
	cout<<"\n*****IsIntInterval ? 2:  "<<isInInterval(test1, 2)<<endl;
	cout<<"\n*****IsIntInterval ? 3:  "<<isInInterval(test1, 3)<<endl;
	cout<<"\n*****IsIntInterval ? 4: "<<isInInterval(test1, 4)<<endl;
	cout<<"\n*****IsIntInterval ? 5: "<<isInInterval(test1, 5)<<endl;
	cout<<"\n*****IsIntInterval ? 6: "<<isInInterval(test1, 6)<<endl;
	cout<<"\n*****IsIntInterval ? 11: "<<isInInterval(test1, 11)<<endl;
	cout<<"\n*****IsIntInterval ? 12: "<<isInInterval(test1, 12)<<endl;

	
	return 0;
}






