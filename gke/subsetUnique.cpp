/*
S = {a, b, c} 
then P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.

Debugging Learnings:

1. C style string size includes NULL character as well
	E.g., char array1 = "ab"  -> sizeof(array1)/sizeof(array1[0] = 3
2. You can return a vector from function and compiler does RVO optimization 
	to copy it in the caller function.
3. You can update std::map by passing it as a reference variable. 
	E.g std::map<int, int> m1; callee_function(std::map<int, int> & m) {..}


*/

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;



std::vector<std::string> printPowerSet(char *input, int len)
{
	cout<<"Len: "<<len<<endl;
	int power_set_size = pow(2, len);
	cout<<"power set Len: "<<power_set_size<<endl;
	std::vector<std::string> final;
	for(int i = 0; i < power_set_size; i++)
	{
		int curNum = i;

		std::string s1;

		for(int i = 0; i < len; i++)
		{
			//Extract ith bit from curNum
			if((curNum & (1<<i)) > 0)
			{
				s1.push_back(input[i]);
			}
		}

		final.push_back(s1);
	}

	
	return final;
}

int main()
{
	char array1[] = "abc";
	
	std::vector<std::string> final;
	final = printPowerSet(array1, sizeof(array1)/sizeof(array1[0]) - 1);


	for(int i = 0; i < final.size(); i++)
	{
		cout<<"i val"<<i<<": "<<final[i]<<endl;
	}
	
	return 0;
}			
			
