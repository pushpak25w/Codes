#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node *next;
};

void push(Node **head,int newData){
	Node *newNode=new Node();
	newNode->val=newData;
	newNode->next=*head;
	(*head)=newNode;
}

void deleteNode(Node **head,int key){
	Node *temp=*head;
	Node *prev=NULL;
	if(temp==NULL)return;
	if(temp->val==key){
		(*head)=temp->next;
		delete temp;
		return;
	}
	else{
		while(temp!=NULL && temp->val!=key){
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL)
			return;
		prev->next=temp->next;
		delete temp;
	}
}

void deleteNodeR(Node** head,int key){
	if((*head)==NULL){
		cout<<"Element doesn't exist"<<endl;
		return;
	}
	if((*head)->val==key){
		Node *t=*head;
		(*head)=(*head)->next;
		delete t;
		return;
	}
	deleteNodeR(&(*head)->next,key);
}

void printList(Node *head){
	if(head==NULL){
		cout<<"list is empty"<<endl;
	}
	while(head!=NULL){
		cout<<head->val<<' ';
		head=head->next;
	}
	cout<<endl;
}

void deleteList(Node **head){
	Node *curr=*head;
	Node *next=NULL;
	while(curr!=NULL){
		next=curr->next;
		free(curr);
		curr=next;
	}
	*head=NULL;
}
int main(){
	Node *head=NULL;
	push(&head,7);
	push(&head,1);
	push(&head,3);
	push(&head,2);
	printList(head);
	deleteNode(&head,3);
	deleteNodeR(&head,7);
	printList(head);
	//deleteList(&head);
	//printList(head);
	return 0;
}