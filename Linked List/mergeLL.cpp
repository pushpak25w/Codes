#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node* next;
	Node(int val){
		this->val=val;
	}
};

Node* mergeSorted1(Node* a,Node* b){
	Node* dummy=new Node(0);
	Node* tail=dummy;
	while(1){
		if(a==NULL){
			tail->next=b;
			break;
		}
		if(b==NULL){
			tail->next=a;
			break;
		}
		if(a->val<=b->val){
			tail->next=a;
			a=a->next;
		}
		else{
			tail->next=b;
			b=b->next;
		}
		tail=tail->next;
	}
	return dummy->next;
}

Node *mergeSorted2(Node *a,Node *b){
	Node* start=new Node(0);
	Node* dummy=start;
	while(a && b){
		if(a->val<b->val){
			start->next=a;
			a=a->next;
		}
		else{
			start->next=b;
			b=b->next;
		}
		start=start->next;
	}
	if(a==NULL){
		start->next=b;
	}
	else if(b==NULL){
		start->next=a;
	}
	return dummy->next;
}

Node *mergeSorted3(Node *a,Node *b){
	Node* tail=NULL;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	if(a->val<b->val){
		tail=a;
		tail->next=mergeSorted3(a->next,b);
	}
	else{
		tail=b;
		tail->next=mergeSorted3(a,b->next);
	}
	return tail;
}

void printList(Node* Node)
{
    while (Node != NULL) {
        cout << Node->val << " ";
        Node = Node->next;
    }
}
 
int main(){
	Node *res=NULL;
	Node* a = new Node(5);
    a->next = new Node(10);
    a->next->next = new Node(15);
    a->next->next->next = new Node(40);
 
    Node* b = new Node(2);
    b->next = new Node(3);
    b->next->next = new Node(20);
 
    cout << "List A before merge: \n";
    printList(a);
 
    cout << "\nList B before merge: \n";
    printList(b);
 
    /* merge 2 sorted Linked Lists */
    res = mergeSorted1(a, b);
 
    cout << "\nMerged Linked List is: \n";
    printList(res);
 
    return 0;
}