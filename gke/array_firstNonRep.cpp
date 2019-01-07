/* 


Find first non - rep in O(n) time in one loop iteration only 
*/


#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;




char findFirstNonRep(char *arr, int len)
{
	if(arr == NULL || len <= 0)
	{
		return -1;
	}

	std::unordered_map<char, int> hashCount;
	std::unordered_map<char, int> hashIsSeenOnce;
	std::map<int, char> hashFirstIndexSeen;


	std::unordered_map<char, int>::iterator it1;
	std::map<int, char>::iterator it2;

	for(int i = 0; i < len; i++)
	{
		char curElem = arr[i];

		it1 = hashCount.find(curElem);
	
		if(it1 != hashCount.end())
		{
			//Already exists, Is seen more than once

			hashCount[curElem]++;

			//Adjust other hashes to reflect this truth

			it1 = hashIsSeenOnce.find(curElem);
			if(it1 != hashCount.end())
			{
				hashFirstIndexSeen.
					erase(hashIsSeenOnce[curElem]);	
				hashIsSeenOnce.erase(curElem);
			}
		}
		else
		{
			hashCount[curElem] = 1;
			hashIsSeenOnce[curElem] = i;
			hashFirstIndexSeen[i] = curElem;
		}
	

		if(i == len - 1)
		{
			for(it2 = hashFirstIndexSeen.begin(); 
				it2 != hashFirstIndexSeen.end(); it2++)
			{
				return it2->second;
			}
		}
	}

	return -1;
}


int main()
{
	//Test cases


	char string1[] = "TeeksforTeeks";
	char string2[] = "TeeksQuiz";

	
	cout<<findFirstNonRep(string1, sizeof(string1)/
		sizeof(string1[0]))<<endl;
	cout<<findFirstNonRep(string2, sizeof(string2)/
		sizeof(string2[0]))<<endl;

	return 0;

}








	



		

			
	

	






