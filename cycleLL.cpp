#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int key;
	Node* next;
	Node(int key){
		this->key=key;
	}
};

void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

Node* detectNremove(Node *head){
	Node *slow=head,*fast=head,*prevSlow;
	while(slow&&fast&&fast->next){
		prevSlow=slow;
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			break;
		}
	}
	Node *prev;
	while(slow!=prevSlow){
		prev=slow;
		slow=slow->next;
	}
	//cout<<prevFast->key<<' '<<fast->key<<' '<<slow->key;
	prev->next=NULL;
	return head;
} 

int main()
{
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next>next->next;
 
    detectNremove(head);
 
    cout << "Linked List after removing loop \n";
    printList(head);
    return 0;
}