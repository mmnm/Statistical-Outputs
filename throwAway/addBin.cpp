#include<iostream>
using namespace std;





int sumDigit(int a, int b, int *carry)
{

    int sum = a + b + *carry;
    cout<<"Sum: "<<sum<<endl;
    *carry = 0;
    
    switch(sum)
    {
        case 2:
            sum = 0;
            *carry = 1;
            break;
        case 3:
            sum = 1;
            *carry = 1;
        default:
            break;
    }
    
        
    return sum;
}

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a;
    
    if(len_b > len_a)
    {
        max_len = len_b;
    }
    
    
    
    char *ans = (char *) malloc(sizeof(char) * (max_len + 2)); 
    int m = max_len;
    
    //Process the adds for a and b
    int j = len_a - 1;
    int k = len_b - 1;
    
    int carry = 0;
    int sum = 0;
    
    
    
    while(j >= 0 || k >= 0) 
    {
        if(j >= 0 && k >= 0)
        {
            sum = sumDigit((int)(a[j] - '0'), b[k] - '0', &carry);
            j--;
            k--;
        }
        else if(j >= 0)
        {
            sum = sumDigit((int)(a[j] - '0'), 0, &carry);
            j--;
        }
        else if(k >= 0)
        {
            sum = sumDigit(0, (int)(b[k] - '0'), &carry);
        k--;

        }
        ans[m--] = (char) (sum + '0');
        
    }
   
    if(carry != 0)
    {
    ans[m--] = carry + '0';
    carry = 0;
    }
 
    while(m >=0)
    {
    cout<<"Are we : "<<m<<endl;
        ans[m--] = 0 + '0';
    }
 
   ans[max_len + 1] = '\0';
    
    return ans;

}

void printChars(char *a)
{
    int len = strlen(a);
    cout<<"Len is: "<<len<<endl;
    for(int i = 0; i < len; i++)
    {
        cout<<a[i]<<" ";
    }

}


int main()
{
    char *a = "11";
    char *b = "1";

    char *c = NULL;

    c = addBinary(a, b);

    printChars(c);



    return 0;

}
