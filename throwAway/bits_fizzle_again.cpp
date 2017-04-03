#include<iostream>
#include<climits>


using namespace std;



int getBit(int num, int i)
{
	num = num & (1 << i);

	return num > 0 ? 1: 0;

}


int setBit(int num, int i) 
{
	int mask = 1 << i;

	return num | mask;

}

int clearBit(int num, int i) 
{
	int mask = 1 << i;
	mask = ~mask;

	return num & mask;
}

int clearBitsMSBThroughI(int num, int i)
{
	int mask = 1 << i;
	mask -= 1;
	return num & mask;

}

int clearBitsIthrough0(int num, int i) 
{
	int mask = (1 << i) - 1;
	mask = ~mask;
	return num & mask;
}

int updateBit(int num, int i, int v)
{
	
	num = clearBit(num, i);
	int mask = 1 << v;
	return num | mask;

}

int swizzleBit(int num) 
{

	int len_int = sizeof(num) * CHAR_BIT;

	for(int i = 0; i < len_int; i+=2)
	{
		int i_bit = getBit(num, i);
		int iplus_bit = getBit(num, i + 1);

		//Swap i and i + 1 bit 
		
		num = updateBit(num, i + 1, i_bit);
		num = updateBit(num, i, iplus_bit);
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

	return 0;
}

