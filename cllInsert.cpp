#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node* addEmpty(struct Node* last,int data){
	if(last!=NULL)
		return last;
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	last->next=last;
	return temp;
}

struct Node *addBegin(struct Node* last,int data){
	if(last==NULL)
		return addEmpty(last,data);
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=last->next;
	last->next=temp;
	return last;
}

struct Node *addEnd(struct Node* last,int data){
	if(last==NULL)
		return addEmpty(last,data);
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=last->next;
	last->next=temp;
	return temp;
}

struct Node* addAfter(struct Node* last,int data,int item){
	if(last==NULL)return NULL;
	struct Node* temp,*p=last->next;
	if(last->data==item)
		return addEnd(last,data);
	while(p!=last){
		if(p->data==item){
			temp=(struct Node*)malloc(sizeof(struct Node));
			temp->data=data;
			temp->next=p->next;
			p->next=temp;
			return last;
		}
		p=p->next;
	}
	cout<<item<<" is not in the list"<<endl;
	return last;
}

void traverse(struct Node* last){
	struct Node* temp=last->next;
	while(temp!=last){
		cout<<temp->data<<' ';
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
    struct Node *last = NULL;
 
    last = addEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    //last = addAfter(last, 10, 8);
 
    traverse(last);
 
    return 0;
}