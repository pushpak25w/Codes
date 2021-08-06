#include<bits/stdc++.h>
using namespace std;
class Graph
{
private:
	list<int> *l;
	int v;
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
	void bfs(int src,int dest=-1){
		unordered_set<int>isVisited;
		queue<int>q;
		vector<int>dist(v,0);
		vector<int>parent(v,-1);
		q.push(src);
		isVisited.insert(src);
		parent[src]=src;
		dist[src]=0;
		while(!q.empty()){
			//cout<<q.front()<<" ";
			for(auto nbr:l[q.front()]){
				if(isVisited.find(nbr)==isVisited.end()){
					q.push(nbr);
					parent[nbr]=q.front();
					dist[nbr]=dist[q.front()]+1;
					isVisited.insert(nbr);
				}
			}
			q.pop();
		}
		for(int i=0;i<v;i++){
			cout<<"shortest distance to "<<i<<" is "<<dist[i]<<endl;
		}
		if(dest!=-1){
			int temp=dest;
			while(temp!=src){
				cout<<temp<<"---";
				temp=parent[temp];
			}
			cout<<src<<endl;
		}
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
	g.bfs(1,6);
	return 0;
}