/**
Add two Link lists

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    struct ListNode* l2, int carry) 
 {
    int curSum = 0;
    
    if(l1 == NULL && l2 == NULL && carry == 0)
    {
        return NULL;
    }
    else if(l1 != NULL && l2 != NULL)
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
    
    curSum = curSum + carry;
    carry = 0;
    
    if(curSum >= 10)
    {
        curSum -= 10;
        carry = 1;
    }
    
    if(l1 != NULL)
    {
        l1 = l1->next;
    }
    if(l2 != NULL)
    {
        l2 = l2->next;
    }

    struct ListNode *cur = newNode(curSum);
    cur->next = addTwoNumbersUtil(l1, l2, carry);
    return cur;
 
     
 }
    
    
 
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* head = NULL;
    return addTwoNumbersUtil(l1, l2, carry);
    
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
    struct ListNode *l1 = newNode(2);
    l1->next = newNode(4);
    l1->next->next = newNode(3);
    
    struct ListNode *l2 = newNode(7);
    l2->next = newNode(0);
    l2->next->next = newNode(8);

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
    l2->val = 5;
    l2->next->val = 6;
    l2->next->next->val = 4;

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
