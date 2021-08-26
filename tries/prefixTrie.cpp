#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char val;
    unordered_map<char,Node*>check;
    bool isTerminal;
    Node(){

    }
    Node(char val){
        this->val=val;
        this->isTerminal=false;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root=new Node('\0');
    }
    void insert(string word){
        Node* temp=root;
        for(char letter:word){
            if(temp->check.count(letter)==0){
                Node* newNode=new Node(letter);
                temp->check[letter]=newNode;
            }
            temp=temp->check[letter];
        }
        temp->isTerminal=true;
    }
    bool search(string word){
        Node* temp=root;
        for(char letter:word){
            if(temp->check.count(letter)>0){
                temp=temp->check[letter];
            }
            else return false;
        }
        return temp->isTerminal;
    }
};
int main(){
    string words[]={"apple","ape","no","news","never","not"};
    Trie t;
    for(auto word:words){
        t.insert(word);
    }
    int q;
    cin>>q;
    string searchWord;
    while(q--){
        cin>>searchWord;
        if(t.search(searchWord)){
            cout<<"yes its there"<<endl;
        }
        else{
            cout<<"nope not there"<<endl;
        }
        cout<<"anything else?"<<endl;
    }
}
