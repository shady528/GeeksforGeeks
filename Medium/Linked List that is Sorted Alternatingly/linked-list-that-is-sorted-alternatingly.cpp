//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
         // Code here
         Node *curr = *head;
         Node *head1 = new Node(-1);
         Node *curr1 = head1;
         Node *curr2 = NULL;
         int i=0;
         while(curr){
             if(i%2==0){
                 curr1->next = curr;
                 curr1 = curr;
                 curr = curr->next;
                 curr1->next = NULL;
             }
             else{
                  Node *temp = curr;
                  curr = curr->next;
                  temp->next = curr2;
                  curr2 = temp;
                  
             }
             i++;
             
         }
         Node *currAns = new Node(-1);
         curr = currAns;
         Node *temp = head1;
         head1=head1->next;
         delete(temp);
         while(head1 && curr2){
             if(head1->data<curr2->data){
                 curr->next = head1;
                 head1= head1->next;
                 curr = curr->next;
             }
             else{
                 curr->next = curr2;
                 curr2 = curr2->next;
                 curr=curr->next;
             }
         }
         if(head1){
             curr->next = head1;
         }
         if(curr2){
             curr->next = curr2;
         }
         *head = currAns->next;
         delete(currAns);
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends