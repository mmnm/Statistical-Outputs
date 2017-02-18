/*
Clone a linked list with next and random pointer in O(1) space

*/

#include<iostream>
#include<map>

using namespace std;


struct Node 
{
	int data;
	struct Node *next;
	struct Node *random;
};



struct Node * newNode(int data)
{
	struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = temp->random = NULL;
	return temp;
}

struct Node * clone_arbit_list_usinghash(struct Node *head)
{
		
	std::map<struct Node *, struct Node *> hashMap;
	std::map<struct Node *, struct Node *>::iterator  it;


	//Traverse the current list and create nodes

	struct Node *temp = head;
	struct Node *randomNew = NULL;

	while(temp != NULL)
	{
		//Create new node
		struct Node *curNew = newNode(temp->data);

		hashMap[temp] = curNew;

		if(randomNew != NULL)
		{
			randomNew->next = curNew;
		}
		
		randomNew = curNew;
		temp = temp->next;
	}
	

	//Now traverse the original list and assign arbit nodes

	temp = head;
	while(temp != NULL)
	{
		//Get Arbitray node

		struct Node *arbit = temp->random;
		
		//Get corresponding newNode

		struct Node *newN = hashMap[temp];

		newN->random = hashMap[arbit];
		temp = temp->next;

	}

	cout<<"Returning head: "<<hashMap[head]<<endl;
	return hashMap[head];

}

void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}



// Driver code
int main()
{
    Node* start = newNode(1);
    start->next = newNode(2);
    start->next->next = newNode(3);
    start->next->next->next = newNode(4);
    start->next->next->next->next = newNode(5);
 
    // 1's random points to 3
    start->random = start->next->next;
 
    // 2's random points to 1
    start->next->random = start;
 
    // 3's and 4's random points to 5
    start->next->next->random =
                    start->next->next->next->next;
    start->next->next->next->random =
                    start->next->next->next->next;
 
    // 5's random points to 2
    start->next->next->next->next->random =
                                      start->next;
 
    cout << "Original list : \n";
    print(start);
 
    cout << "\nCloned list : \n";
    Node *cloned_list = clone_arbit_list_usinghash(start);
    print(cloned_list);
 
    return 0;
}



		
	
		
		
			

		
		
					









