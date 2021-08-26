#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char val;
    unordered_map<char,Node*>children;
    bool isTerminal;
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
            if(temp->children.count(letter)==0){
                Node* newNode=new Node(letter);
                temp->children[letter]=newNode;
            }
            temp=temp->children[letter];
        }
        temp->isTerminal=true;
    }
};

void searchHelper(Trie t,string document,int i,unordered_map<string,bool>&m){
    Node* temp=t.root;
    for(int j=i;j<document.length();j++){
        if(temp->children.count(document[j])==0)return;
        temp=temp->children[document[j]];
        if(temp->isTerminal){
            string s=document.substr(i,j-i+1);
            m[s]=true;
        }
    }
    return;
}

void documentSearch(string document,vector<string>&words){
    Trie t;
    for(string word:words){
        t.insert(word);
    }
    unordered_map<string,bool>m;
    for(int i=0;i<document.length();i++){
        searchHelper(t,document,i,m);
    }
    for(auto word:words){
        if(m[word]){
            cout<<word<<" true"<<endl;
        }
        else{
            cout<<word<<" false"<<endl;
        }
    }
}

int main(){
     string document  ="little cute cat loves to code in c++, java & python";
    vector<string> words{"cute cat", "ttle", "cat","quick","big"};
    documentSearch(document,words);
}
