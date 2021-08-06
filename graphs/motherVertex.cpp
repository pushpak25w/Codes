#include <bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int>*l;
public:
	Graph(int V){
		this->V=V;
		l=new list<int>[V];
	}
	void addEdge(int i,int j){
		l[i].push_back(j);
	}
	void dfsUtil(int v,vector<bool>&isVisited){
		isVisited[v]=true;
		for(auto& it:l[v])
			if(!isVisited[it])
				dfsUtil(it,isVisited);
	}
	int findMother(){
		vector<bool>isVisited(V,false);
		int v=0;
		for(int i=0;i<V;i++){
			if(!isVisited[i]){
				dfsUtil(i,isVisited);
				v=i;
			}
		}
		fill(isVisited.begin(),isVisited.end(),false);
		dfsUtil(v,isVisited);
		for(int i=0;i<V;i++){
			if(isVisited[i]==false){
				return -1;
			}
		}
		return v;
	}
};
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
 
    cout << "A mother vertex is " << g.findMother();
 
    return 0;
}