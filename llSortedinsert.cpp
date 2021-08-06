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
		return;
	}
	if((*head)->val>=val){
		newNode->next=(*head);
		(*head)=newNode;
		return;
	}
	Node* temp=(*head),*prev=(*head);
	while(temp->next!=NULL){
		if(temp->val>=val){
			newNode->next=temp;
			prev->next=newNode;
			return;
		}
		prev=temp;
		temp=temp->next;
	}
	temp->next=newNode;
	newNode->next=NULL;
}

void printList(Node *start)
{
    while(start){
    	cout<<start->val<<' ';
    	start=start->next;
    }
    cout<<endl;
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