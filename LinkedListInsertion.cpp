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

void insertAfter(Node *prev,int newData){
	if(prev==NULL){
		cout<<"prevNode cannot be NULL"<<endl;
		return;
	}
	Node* newNode=new Node(newData);
	newNode->next=prev->next;
	prev->next=newNode;
}
void append(Node **head,int newData){
	Node *newNode=new Node(newData);
	Node *last=*head;
	newNode->next=NULL;
	if(*head==NULL){
		(*head)=newNode;
		return;
	}
	else{
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=newNode;
	}
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->val;
        node = node->next;
    }
}

int main(){
	Node *head=NULL;
	append(&head,6);
	push(&head,7);
	push(&head,1);
	append(&head,4);
	insertAfter(head->next,8);
	printList(head);
	return 0;
}