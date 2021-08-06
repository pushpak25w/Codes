#include<bits/stdc++.h>
using namespace std;
class Graph{
private:
	int v;
	list<int> *l;
public:
	Graph(int v){
		this->v=v;
		l=new list<int>[v];
	}
	void addEdge(int i,int j,bool undir=true){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}
	void dfsHelper(int node,bool *isVisited){
		isVisited[node]=true;
		cout<<node<<endl;
		for(int nbr:l[node]){
			if(!isVisited[nbr]){
				dfsHelper(nbr,isVisited);
			}
		}
		return;
	}
	void dfs(int src){
		bool *isVisited=new bool [v]{0};
		dfsHelper(src,isVisited);
	}
};
int main(){
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(2,3);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.dfs(1);
	return 0;
}