/*
Length of the longest valid substring
Given a string consisting of opening and closing parenthesis, find length of the longest valid parenthesis substring.

Examples:

Input : ((()
Output : 2
Explanation : ()

Input: )()())
Output : 4
Explanation: ()() 

Input:  ()(()))))
Output: 6
Explanation:  ()(())                                                                   

*/

#include<iostream>
#include<stack>

using namespace std;



int longest_valid(char *input_arr, int len)
{
	if(len == 0)
		return 0;

	if(input_arr == NULL)
		return 0;

	std::stack<char> s1;

	//Algo:
	//for in loop
	//if right bracket
		//if stack len is empty, 
			//then dont push/pop right bracket and reset cur len
		//else pop stack bracket, increment cur, check High count 
		
	//if left bracket
		//push left bracket in stack


	//return high_count

	int cur_count = 0;
	int high_count = -1;

	for(int i = 0; i < len; i++)
	{
		char cur = input_arr[i];
		if(cur == '(')
		{
			s1.push(cur);
		}
		else if(cur == ')')
		{
			if(s1.size() <= 0)
			{
				cur_count = 0;
			}
			else 
			{
				char temp = s1.top();
				s1.pop();
				if(temp == '(')
				{
					cur_count += 2;
				}
				else 
				{
					cout<<"Debug this"<<endl;
				}

			}
		}
		
		if(high_count < cur_count)
		{
			high_count = cur_count;
		}
		
	}


	return high_count;


}


// Driver program
int main()
{
    char str[] = "((()()";
  
    cout << longest_valid(str, strlen(str)) << endl;
 
    char str2[] = "()(()))))";
    cout << longest_valid(str2, strlen(str2)) << endl;

    return 0;
}
