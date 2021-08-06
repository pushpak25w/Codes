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

class linkedList{
public:
	Node *head;
	linkedList(){
		head=NULL;
	}
	void reverse(){
		Node *curr=head,*prev=NULL,*next=NULL;
		while(curr){
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		head=prev;
	}
	Node* reverse(Node *head){
		if(head==NULL || head->next==NULL){
			return head;
		}
		Node *rest=reverse(head->next);
		head->next->next=head;
		head->next=NULL;
		return rest;
	}
	void print(){
		Node *temp=head;
		while(temp){
			cout<<temp->val<<' ';
			temp=temp->next;
		}
		cout<<endl;
	}
	void push(int val){
		Node *newNode=new Node(val);
		newNode->next=head;
		head=newNode;
	}
};

int main(){
	linkedList ll;
	ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();
    ll.head=ll.reverse(ll.head);
    ll.print();
    return 0;
}