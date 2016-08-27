/*

Remove characters from the first string which are present in the second string
Write an efficient C function that takes two strings as arguments and 
removes the characters from first string which are present in second string 
(mask string).

Example 
char str[]         = "geeksforgeeks";
char mask_str[]  = "mask";

Output: geeforgee




*/

#include<iostream>
#include<cstdio>


using namespace std;


char * removeDirtyChars(char * str1, char * str2)
{
	if(str1 == NULL || str2 == NULL)
	{
		return NULL;
	}

	bool hash_str2[128] = {false};

	char *ptr = str2;

	while(*ptr != '\0')
	{
		char cur = *ptr;

		if(hash_str2[cur] == false)
		{
			hash_str2[cur] = true;
		}

		ptr++;
	}

	int i = 0;
	int j = 0;

	ptr = str1;

	while(*(ptr + j) != '\0')
	{
		char cur = *(ptr + j);

		if(hash_str2[cur] == false)
		{
			*(ptr + i) = *(ptr + j);
			i++;
		}	
		j++;
	}

	*(ptr + i) = '\0';

	return ptr;

}

int main()
{
	char str[]         = "geeksforgeeks";
	char mask_str[]  = "mask";
	printf("%s", removeDirtyChars(str, mask_str));
	return 0;
}






