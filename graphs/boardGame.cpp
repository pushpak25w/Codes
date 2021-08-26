#include<bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

class Node{
public:
	unordered_map<char,Node*>children;
	char val;
	bool isTerminal;
	string word;
	Node(){}
	Node(char val){
		this->val=val;
		isTerminal=false;
		word="";
	}
};

class Trie{
public:
	Node* root;
	Trie(){
		root=new Node('\0');
	}
	void addWord(string word){
		Node* temp=root;
		for(char letter:word){
			if(temp->children.find(letter)==temp->children.end()){
				Node* newNode=new Node(letter);
				temp->children[letter]=newNode;
			}
			temp=temp->children[letter];
			temp->word=word;
		}

	}
};

void dfs(char board[M][N],Node* node,int i,int j,bool visited[][N],unordered_set<string>&output){
	char ch=board[i][j];
	if(node->children.count(ch)==0)return;
	visited[i][j]=1;
	node=node->children[ch];
	if(node->isTerminal){
		output.insert(node->word);
	}
	int dx[]={0,1,1,1,0,-1,-1,-1};
	int dy[]={-1,-1,0,1,1,1,0,-1};
	for(int k=0;k<8;k++){
		int x=i+dx[k];
		int y=j+dy[k];
		if(x>=0 && y>=0 && x<N && y<M && !visited[x][y]){
			dfs(board,node,x,y,visited,output);
		}
	}
	visited[i][j]=false;
}

int main(){
	string words[]={"SNAKE","FOR","QUEZ","SNACK","SNACKS","GO","TUNES","CAT"};
	char board[M][N]={ {'S','E','R','T'},
					    {'U','N','K','S'},
						{'T','C','A','T'}};
	Trie t;
	for(auto word:words)
		t.addWord(word);

	unordered_set<string>output;
	bool visited[M][N]={0};
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			dfs(board,t.root,i,j,visited,output);
		}
	}
	for(auto word:output){
		cout<<word<<endl;
	}
}