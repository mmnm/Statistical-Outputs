
/* Implement fizzling with some other utilities as below
Arithmatic shift versus logical shift 

E,g 
-3123333434
shifted 40 times >> would lead to 0




whereas same with >>> logical shift would lead to -1 (11111....)



*/

#include<iostream>
#include<climits>

using namespace std;

int getbit(int num, int i)
{
	int res =  num & (1 << i);
	return res > 0 ? 1: 0;
}


int setbit(int num, int i)
{
	num = num | (1 << i);
	return num;
}

int clearbit(int num, int i)
{
	return num & ~(1 << i);
}

int clearbitsMSBThroughI(int num, int i)
{
	int mask = (1 << (i + 1)) - 1;
	return num & mask;
}

int clearbitsIthrough0(int num, int i)
{
	
	int mask = (1 << (i + 1)) - 1;
	mask = ~mask;
	return num & mask;

}

int updatebit(int num, int i, int v)
{
	if(!(v == 1 || v == 0))
	{
		cout<<"updatebit::Debug this: "<<v<<endl;
		return -1;
	}

	//Clear bit i
	num = num & ~(1 << i);
	//Set bit i 
	if(v == 1)
	{
		num = num | 1 << i;
	}
	return num;
	

}

/* Swizzle bit will swap ith pair with i + 1th pair
E,g 
0111 -> 1011
0101 -> 1010
*/
int swizzlebit(int num)
{
	/* Naive algo: loop through and swap ith bit with i + 1th */

	
	int len_int = sizeof(num) * CHAR_BIT;
	for(int i = 0; i < len_int; i += 2)
	{
		int temp_i = getbit(num, i);
		int temp_i1 = getbit(num, i + 1);
		cout<<endl;
		/*
		cout<<i<<" and "<<i+ 1<< 
			" bits: "<<temp_i<<" " << temp_i1<<endl; */
		num = updatebit(num, i, temp_i1);
		num = updatebit(num, i + 1, temp_i);		

	}

	return num;
}


void printbin(int num)
{
	
	int len_int = sizeof(num) * CHAR_BIT;
	for(int i = len_int - 1; i >= 0; i--)
	{
		int res =  (num & 1<<i) > 0 ? 1: 0;
		cout<<res;
	}
}


int main()
{

	int number = 0;


	//Test cases
	number = 0b1001;
	
	cout<<"\nBit Swizzled for number: "<<endl;
	printbin(number);
	number = swizzlebit(number);
	cout<<" is: "; 
	printbin(number);
	//Test cases
	number = 0b1101;
	
	cout<<"\nBit Swizzled for number: "<<endl;
	printbin(number);
	number = swizzlebit(number);
	cout<<" is: "; 
	printbin(number);
	//Test cases
	number = 0b110011011001101;
	
	cout<<"\nBit Swizzled for number: "<<endl;
	printbin(number);
	number = swizzlebit(number);
	cout<<" is: "; 
	printbin(number);
	return 0;	
}
	










