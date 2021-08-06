#include<bits/stdc++.h>
using namespace std;
class Graph{
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
	void bfs(int src){
		unordered_set<int>isVisited;
		queue<int>q;
		q.push(src);
		while(!q.empty()){
			if(isVisited.find(q.front())==isVisited.end()){
				cout<<q.front()<<" ";
				isVisited.insert(q.front());
				for(auto nbrs:l[q.front()]){
					if(isVisited.find(nbrs)==isVisited.end())
					q.push(nbrs);
				}
			}
			q.pop();
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
	g.bfs(1);
	return 0;
}