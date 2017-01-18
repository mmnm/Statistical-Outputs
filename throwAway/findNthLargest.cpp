/* 

Find the n Smallest element in unsorted array 

Idea 1: we can sort the array in O(nlogn) and do linear sweep of nth elem O(1) ; Time complexity O(nlogn), Space O(n)

Quick sort: T(n) = 2T(n/2) + O(n)

Idea 2: If we use partition routine from Quick sort to find the rank and only recurse to solve it on the part containing the rank and leave the other rank

T(n) = T(n/2) + O(n)

From Master's theorem Time complexity: O(n)

*/

#include<iostream>
using namespace std;



int partition(int *arr, int start , int end)
{
	if(arr == NULL)
	{
		return -1;
	}

	if(start > end)
	{
		return -1;
	}

	if(start == end)
	{
		return start;
	}

	int part_elem = arr[start];
	
	int i = start;

	for(int j = start + 1; j <= end; j++)
	{
		int curElem = arr[j];	
		
		if(curElem < part_elem)
		{
			arr[j] = arr[i+1];
			arr[i+1] = curElem;
			i++;
		}
	}
	//Last swap
		arr[start] = arr[i];
		arr[i] = part_elem;
	return i;

}




int findNthSmallest(int *arr, int start, int end, int n)
{
	if(arr == NULL)
	{
		return -1;
	}

	if(start > end)
	{
		return -1;
	}

	int part_rank = partition(arr, start, end);

	if(part_rank == -1)
	{
		cout<<"Debug part rank issue"<<endl;
		return -1;
	}

	if(part_rank == n - 1)
	{
		return arr[part_rank];
	}
	else if(part_rank < n - 1)
	{
		return findNthSmallest(arr, part_rank + 1, end, n);
	}
	else 
	{
		return findNthSmallest(arr, start, part_rank - 1, n);
	}

}

int main()
{
	int arr1[] = {10,1,2,8,3,7,9,4,6,5};
	int arr1_len = sizeof(arr1)/sizeof(arr1[0]);

	//Test cases

	cout<<"First smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 1)<<endl;
	cout<<"2nd smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 2)<<endl;
	cout<<"3rd smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 3)<<endl;
	cout<<"4th smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 4)<<endl;
	cout<<"5th smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 5)<<endl;
	cout<<"6th smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 6)<<endl;
	cout<<"7th smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 7)<<endl;
	cout<<"8th smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 8)<<endl;
	cout<<"9th smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 9)<<endl;
	cout<<"10th smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 10)<<endl;
	cout<<"11th smallest elem: "<<findNthSmallest(arr1, 0, arr1_len - 1, 11)<<endl;

	return 0;
	


}


		












