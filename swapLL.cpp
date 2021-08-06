#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int val;
	Node *next;
	Node(int val,Node *next){
		this->val=val;
		this->next=next;
	}
	void printList(){
		Node * node=this;
		while(node!=NULL){
			cout<<node->val<<' ';
			node=node->next;
		}
		cout<<endl;
	}
};

void swap(Node *&a,Node *&b){
	Node* temp=a;
	a=b;
	b=temp;
}

void push(Node **head,int newData){
	(*head)=new Node(newData,*head);
}

void swapNodes(Node **head,int x,int y){
	if(x==y)return;
	Node **a=NULL,**b=NULL;
	while((*head)){
		if((*head)->val==x){
			a=head;
		}
		else if((*head)->val==y){
			b=head;
		}
		head=&((*head)->next);
	}
	if(a&&b){
		swap(*a,*b);
		swap((*a)->next,(*b)->next);
	}
}
int main()
{
 
    Node* start = NULL;
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    cout << "Linked list before calling swapNodes() ";
    start->printList();
 
    swapNodes(&start, 6, 1);
 
    cout << "Linked list after calling swapNodes() ";
    start->printList();
}