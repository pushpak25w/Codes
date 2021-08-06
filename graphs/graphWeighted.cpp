#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
	int v;
	list<pair<int,int>>*l;
public:
	Graph(int v){
		this->v=v;
		l=new list<pair<int,int>>[v];
	}
	void addEdge(int i,int j,int wt,bool undir=true){
		l[i].push_back({wt,j});
		if(undir){
			l[j].push_back({wt,i});
		}
	}
	void print(){
		for(int i=0;i<v;i++){
			cout<<i<<"----->";
			for(auto node:l[i]){
				cout<<node.first<<' '<<node.second<<",";
			}
			cout<<endl;
		}
	}
};


int main(){
	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,2);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);
	g.print();
	return 0;
}

