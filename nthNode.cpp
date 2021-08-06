#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int val;
	Node* next;
	Node(int val){
		this->val=val;
	}
};

void nthNode(Node *head,int n){
	Node* main_ptr=head;
	Node* ref=head;
	if(head!=NULL){
		int count=0;
		while(count<n){
			if(ref==NULL){
				cout<<"n is greater than length"<<endl;
				return;
			}
			count++;
			ref=ref->next;
		}
		if(ref==NULL){
			cout<<main_ptr->val<<endl;
		}
		else{
			while(ref!=NULL){
				ref=ref->next;
				main_ptr=main_ptr->next;
			}
			cout<<main_ptr->val<<endl;
		}
	}
}

void push(Node** head,int val){
	Node* newNode=new Node(val);
	newNode->next=(*head);
	(*head)=newNode;
}

int main(){
	Node* head=NULL;
	push(&head, 20);
  	push(&head, 4);
  	push(&head, 15);
  	push(&head, 35);
  	nthNode(head,4);
  	nthNode(head,1);
  	nthNode(head,2);
}