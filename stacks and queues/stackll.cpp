#include<bits/stdc++.h>
using namespace std;

class StackNode{
public:
	int val;
	StackNode* next;
	StackNode(int val,StackNode* next=NULL){
		this->val=val;
		this->next=next;
	}
};

void push(StackNode** root,int val){
	StackNode* newNode=new StackNode(val);
	newNode->next=(*root);
	(*root)=newNode;
}

int isEmpty(StackNode *root){
	return !root;
}

int pop(StackNode** root){
	if(isEmpty(*root)){
		return INT_MIN;
	}
	StackNode* temp=*root;
	(*root)=(*root)->next;
	int popped=temp->val;
	free(temp);
	return popped;
}

int peek(StackNode* root){
	if(isEmpty(root))
		return INT_MIN;
	return root->val;
}

int main()
{
    StackNode* root = NULL;
 
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    cout << pop(&root) << " popped from stack\n";
 
    cout << "Top element is " << peek(root) << endl;
     
    cout<<"Elements present in stack : ";
     //print all elements in stack :
    while(!isEmpty(root))
    {
        // print top element in stack
        cout<<peek(root)<<" ";
        // remove top element in stack
        pop(&root);
    }
 
    return 0;
}