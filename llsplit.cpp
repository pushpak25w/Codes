#include<iostream>
using namespace std;

class Node{
public:
	int val;
	Node* next;
	Node(int val){
		this->val=val;
	}
};
Node* insert(Node* last,int val){
	Node* temp=new Node(val);
	temp->next=last->next;
	last->next=temp;
	last=temp;
	return last;
}

void traverse(Node* last){
	Node* temp=last;
	do{
		cout<<temp->val<<" ";
		temp=temp->next;
	}while(last!=temp);
	cout<<endl;
}
void splitll(Node* head,Node** head1,Node** head2){
	Node *first=head;
	Node* second=head;
	if(head==NULL)return;
	while(second->next!=head && second->next->next!=head){
		first=first->next;
		second=second->next->next;
	}
	if(second->next->next==head){
		second=second->next;
	}
	*head1=head;
	if(head->next!=head)
		*head2=first->next;
	second->next=first->next;
	first->next=head;

}
int main(){
	Node* last=new Node(6);
	last->next=last;
	last=insert(last,4);
	last=insert(last,2);
	last=insert(last,1);
	last=insert(last,3);
	last=insert(last,5);
	last=insert(last,7);
	last=insert(last,8);
	last=insert(last,11);
	last=insert(last,9);
	last=insert(last,10);
	last=insert(last,12);
	cout<<"original list is:"<<endl;
	traverse(last);
	Node* head1,*head2;
	splitll(last,&head1,&head2);
	cout<<"first cll is:"<<endl;
	traverse(head1);
	cout<<"second cll is: "<<endl;
	traverse(head2);
}
