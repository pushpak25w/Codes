#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    unordered_map<char,Node*>check;
    bool isTerminal;
    char val;
    Node(){

    }
    Node(char val){
        this->val=val;
    }
};

class suffixTrie{
public:
    Node* root;
    suffixTrie(){
        root=new Node('\0');
    }
    void insert_helper(string word){
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
    void insert(string word){
        for(int i=0;word[i]!='\0';i++){
            insert_helper(word.substr(i));
        }
    }
    bool search(string word){
        Node* temp=root;
        for(char letter:word){
            if(temp->check.count(letter)==0)
                return false;
            temp=temp->check[letter];
        }
        return temp->isTerminal;
    }
};

int main(){
    string word="hello";
    string suffixes[]={"ell","lo","ello","hello"};
    suffixTrie t;
    t.insert(word);
    for(auto sf:suffixes){
        if(t.search(sf)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }

}
