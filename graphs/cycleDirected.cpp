#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
	int v;
	list<int>*l;
public:
	Graph(int v){
		this->v=v;
		l=new list<int>[v];
	}
	void addEdge(int i,int j){
		l[i].push_back(j);
	}
	bool dfs(int src,vector<bool>&isVisited,vector<bool>&stack){
		isVisited[src]=true;
		stack[src]=true;
		for(int nbr:l[src]){
			if(stack[nbr])
				return true;
			else if(isVisited[nbr]==false){
				if(dfs(nbr,isVisited,stack))
					return true;
			}
		}
		stack[src]=false;
		return false;
	}
	bool cycleDetect(){
		vector<bool>isVisited(v,false);
		vector<bool>stack(v,false);
		for(int i=0;i<v;i++){
			if(!isVisited[i]){
				if(dfs(i,isVisited,stack))
					return true;
			}
		}
		return false;
	}
};int main(){
	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	cout<<g.cycleDetect()<<endl;
	return 0;
}