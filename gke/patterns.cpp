#include<iostream>
#include<cstdlib>

using namespace std;
bool isReducedNULL(char *p)
{
    int i = 0;
    int len = strlen(p);
    
    if(len <= 1)
    {
        return false;
    }
    
    for(i = 0; i < len; i += 2)
    {
        if(i == len - 1)
        {
            if(p[i] != '*')
            {
                return false;
            }
            break;
        }
        if(p[i + 1] != '*')
        {
            return false;
        }
    }
    
   
    
    return true;
}

int matchEnd(char *s)
{
    if(s == NULL)
    {
        return -1;
    }

    char start = s[0];
    int len = strlen(s);
    
    int i = 0;
    for(; i < len; i++)
    {
        if(s[i] != start)
        {
            break;
        }
    }
    
    return i - 1;
    
}

bool isMatch(char* s, char* p) {
    
    if(s == NULL || p == NULL)
    {
        return false;
    }
    
    //Base cases
    if(s[0] == '\0' && p[0] == '\0')
    {
        return true;
    }
    else if(p[0] == '\0')
    {
        return false;
    }
    else if(s[0] == '\0')
    {
        return isReducedNULL(p);
    }
    
    int s_len = strlen(s);
    int p_len = strlen(p);
    
    char curS = s[0];
    char curP = p[0];
    char nextP = -1;
    
    if(1 < p_len)
    {
        nextP = p[1];
    }
    
    if(nextP != '*')
    {
        if(curS == curP || curP == '.')
        {
            return isMatch(s + 1, p + 1);
        }
        else if(curS != curP)
        {
            return false;
        }
    }
    else 
    {
        if(curP == '.')
        {
            if(isMatch(s, p + 2))
            {
                    return true;
            }
            
            for(int i = 0; i < s_len; i++)
            {
                if(isMatch(s + i + 1, p + 2))
                {
                    return true;
                }
            }
            return false;
        }
        else 
        {
            if(curS != curP)
            {
                return isMatch(s, p + 2);
            }
          
            int end_index = matchEnd(s);
            for(int i = 0; i <= end_index + 1; i++)
            {
                if(isMatch(s + i, p + 2))
                {
                    return true;
                }
            }
            return false;
        }
    }
    
    return false;

    
}
int main()
{

	char test_a_s[10] = "a";
	char test_a_p[10] = ".*..a*";
	cout<<isMatch(test_a_s, test_a_p)<<endl;

	char test_b_s[10] = "a";
	char test_b_p[10] = "a";
	cout<<isMatch(test_b_s, test_b_p)<<endl;


	char test_c_s[10] = "aaab";
	char test_c_p[10] = "a*b";
	cout<<isMatch(test_c_s, test_c_p)<<endl;
	
	return 0;


}



