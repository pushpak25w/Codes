#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
	list<int>*l;
	int v;
public:
	Graph(int v){
		this->v=v;
		l=new list<int>[v];
	}
	void addEdge(int i,int j){
		l[i].push_back(j);
		l[j].push_back(i);
	}
	bool dfs(int node,vector<bool>&isVisited,int parent){
		isVisited[node]=true;
		for(auto nbr:l[node]){
			if(!isVisited[nbr]){
				bool nbrFoundACycle=dfs(nbr,isVisited,node);
				if(nbrFoundACycle)
					return true;
			}
			else if(nbr!=parent)
				return true;
		}
		return false;
	}
	bool cycleDetect(){
		vector<bool>isVisited(v,false);
		return dfs(0,isVisited,-1);
	}
}; 
int main(){
	Graph g(3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	cout<<g.cycleDetect()<<endl;
	return 0;
}