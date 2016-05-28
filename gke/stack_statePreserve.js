#include <iostream>
using namespace std;





/* 
Your previous Plain Text content is preserved below:

// Implement a persistent (i.e. immutable) stack data structure with 
// the following interface:

type stack (of integers)

*/

struct stack
{
  int data;
  struct stack *pointsToStack;
};


struct stack * empty()
{
  return NULL;
}

struct stack * push(int data, struct stack * s) 
{
//No checks for s, intentionally to preserve, and it being harmless  
struct stack *newStack = (struct stack *)malloc(sizeof(struct stack));
newStack->data = data;

//Is there a problem if we use this for pop
// newStack->pointsToStack = copyImmutableForms(s);

newStack->pointsToStack = s;
return newStack;


}

struct stack * pop(struct stack *s) 
{

  if(s == NULL)
  {
    return NULL;
  }


  struct stack * temp = s->pointsToStack;
  free(s);
  return temp;
}


int peek(struct stack *s)
{

  if(s == NULL)
  {
    return -1;
  }

  return s->data;

}



int size(struct stack *s)
{

  if(s == NULL)
  {
    return 0;
  }

  struct stack *temp = s;
  int count = 1;
  while(temp != NULL)
  {
    temp = temp->pointsToStack;
    count++;
  }

  return count;




}


void printStack(struct stack *s)
{
  if(s == NULL)
  {
    cout<<" Empty"<<endl;
    return;
  }

  while(s != NULL)
  {
    cout<<" "<<s->data<<" "<<s->pointsToStack;
    s = s->pointsToStack;
  }


}


int main() {


//   empty   : () -> stack  // i.e. a constructor
// size    : stack -> int
// peek    : stack -> int // returns the most recently pushed element
// *push   : (int, stack) -> stack
// *pop    : stack -> stack

// s0 = empty()
// s1 = push(5, s0) // [5]
// s2 = push(6, s1) // [6, 5]
// s3 = push(7, s1) // [7, 5]
// s4 = pop(s3) // [5] 



struct stack *s0 = empty();

cout<<"\nTest case 1"<<endl;
printStack(s0); 
cout<<endl;

cout<<"\nTest case 2"<<endl;
struct stack *s1 = push(5,s0);
printStack(s1); // 5 0
cout<<endl;

cout<<"\nTest case 3"<<endl;
struct stack *s2 = push(6, s1);
printStack(s2); // 6 something 5 0
cout<<endl;

cout<<"\nTest case 4"<<endl;
struct stack *s3 = push(7,s1);
printStack(s3); 
cout<<endl;

cout<<"\nTest case 5"<<endl;
struct stack *pop_s3 = pop(s3);
printStack(pop_s3); 


return 0;
}


/*

assert size(s0) == 0
assert peek(s1) == 5
assert size(s1) == 1
assert peek(s2) == 6
assert size(s2) == 2
assert peek(s3) == 7
assert size(s3) == 2
assert peek(s4) == 5
assert size(s4) == 1
*/