/**
Add two Link lists

Input: (3 -> 4 -> 2) + (4-> 6 -> 5)
Output: 8 -> 0 -> 7

Debugging:
1. Please remember that if you want to make changes to a varible
while passing on a recursion, always remember what will happen
after the recursive call

E.g., 

	if(l1_copy != NULL)
	{
		l1_copy = l1_copy->next;
	}

	Is used now instead of using l1 directly, as l1 value needs 
	to be the same 
	after the recursive call but we still need to protect the state of 
	l1 if already is NULL then we dont increment again
	Please see line 59 - 68




 */

#include<iostream>
using namespace std;
 
struct ListNode {
      int val;
      struct ListNode *next;
};
 
 struct ListNode* newNode(int data)
 {
     struct ListNode *temp = (struct ListNode *)malloc
     (sizeof(struct ListNode));
     temp->next = NULL;
     temp->val = data;
     return temp;
 }
 
 struct ListNode* addTwoNumbersUtil(struct ListNode* l1, 
    struct ListNode* l2, int &carry) 
 {

	if(l1 == NULL && l2 == NULL)
	{
		return NULL;
	}

	struct ListNode *l1_copy = l1;
	struct ListNode *l2_copy = l2;

	if(l1_copy != NULL)
	{
		l1_copy = l1_copy->next;
	}
	
	if(l2_copy != NULL)
	{
		l2_copy = l2_copy->next;
	}

	struct ListNode *temp = addTwoNumbersUtil(l1_copy, l2_copy, carry);
	
	int curSum = 0;

	if(l1 != NULL && l2 != NULL)
	{
		curSum = l1->val + l2->val;
	}
	else if(l1 != NULL)
	{
		curSum = l1->val;
	}
	else if(l2 != NULL)
	{
		curSum = l2->val;
	}
	else 
	{
		cout<<"Why something not matched?"<<endl;
	}

	curSum += carry;
	carry = 0;

	if(curSum >= 10)
	{
		curSum -= 10;
		carry = 1;
	}

	struct ListNode *curElem = newNode(curSum);
	curElem->next = temp;

	return curElem;

}
    
    
 
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    int carry = 0;
    struct ListNode* sumList = addTwoNumbersUtil(l1, l2, carry);
    struct ListNode* sumHead = NULL;

    if(carry != 0)
    {
	sumHead = newNode(1);
	sumHead->next = sumList;
        carry = 0;
    }
    else 
    {
	sumHead = sumList;
    }	

    return sumHead;

}


void printList(struct ListNode *head)
{
    if(head == NULL)
    {
        return;
    }
    cout<<" "<<head->val;
    printList(head->next);
}

int main()
{
    struct ListNode *l1 = newNode(3);
    l1->next = newNode(4);
    l1->next->next = newNode(2);
    
    struct ListNode *l2 = newNode(9);
    l2->next = newNode(0);
    l2->next->next = newNode(7);

   
    cout<<"List 1: ";
    printList(l1);
    cout<<endl;

    cout<<"List 2: ";
    printList(l2);
    cout<<endl;

    struct ListNode *sumList = addTwoNumbers(l1, l2);
    
    cout<<"Sum List of 1 and 2: ";
    printList(sumList);
    cout<<endl;

 

    //Modify l2
    l2->val = 4;
    l2->next->val = 6;
    l2->next->next->val = 5;

    cout<<"List 1: ";
    printList(l1);
    cout<<endl;

    cout<<"List 2: ";
    printList(l2);
    cout<<endl;

    struct ListNode *sumList1 = addTwoNumbers(l1, l2);
    
    cout<<"Sum List of 1 and 2: ";
    printList(sumList1);
    cout<<endl;



    return 0;



}
