#include<bits/stdc++.h>
using namespace std;

class Stack
{
private:
	static const int max=100;
	int arr[max];
	int top;
public:
	Stack(){top=-1;}
	bool isEmpty();
	bool isFull();
	void pop();
	void push(int x);
	
};

bool Stack::isEmpty(){
	return top==-1;
}

bool Stack::isFull(){
	return top==max-1;
}
void Stack::pop(){
	if(isEmpty()){
		cout<<"Stack Underflow"<<endl;
	}
	cout<<arr[top--]<<endl;
}

int Stack::push(int val){
	if(isFull()){
		cout<<"Stack overflow"<<endl;
	}
	top++;
	arr[top]=val;
}

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	s.pop();
	s.push(4);
	s.pop();
	s.pop();
	s.pop();
}