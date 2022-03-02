#include<iostream>
using namespace std;
class Node{
public:
	int val;
	Node* next;
	Node(int val){
		this->val=val;
		this->next=NULL;
	}
};

void sortedInsert(Node** head,int val){
	Node* newNode=new Node(val);
	if((*head)==NULL){
		(*head)=newNode;
		newNode->next=newNode;
		return;
	}
	if((*head)->val>=val){
		Node* cur=(*head);
		while(cur->next!=(*head))
			cur=cur->next;
		cur->next=newNode;
		newNode->next=(*head);
		(*head)=newNode;
		return;
	}
	Node* temp=(*head),*prev=(*head);
	while(temp->next!=(*head)){
		if(temp->val>=val){
			newNode->next=temp;
			prev->next=newNode;
			return;
		}
		prev=temp;
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->next=(*head);
}

void printList(Node *start)
{
    Node *temp;
     
    if(start != NULL)
    {
        temp = start;
        do {
        cout<<temp->val	<<" ";
        temp = temp->next;
        } while(temp != start);
    }
}

int main()
{
    int arr[] = {12, 56, 2, 11, 1, 90};
    int i;
    Node *start = NULL;
    for (i = 0; i< 6; i++)
    {
        sortedInsert(&start,arr[i]);
    }
    printList(start);
     
    return 0;
}