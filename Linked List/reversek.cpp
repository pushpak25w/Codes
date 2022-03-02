#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int val;
	Node *next;
	Node(int val){
		this->val=val;
	}
};

void push(Node **head,int newData){
	Node* newNode=new Node(newData);
	newNode->next=(*head);
	(*head)=newNode;
}

Node* reverseK(Node *head,int k){
	Node *curr=head,*next=NULL,*prev=NULL;
	int count=0;
	while(curr && count<k){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	if(next!=NULL){
		head->next=reverseK(next,k);
	}
	return prev;
}
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
}

int main()
{
    Node* head = NULL;
 
    /* Created Linked list
       is 1->2->3->4->5->6->7->8->9 */
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    cout << "Given linked list \n";
    printList(head);
    head = reverseK(head, 3);
 
    cout << "\nReversed Linked list \n";
    printList(head);
 
    return (0);
}