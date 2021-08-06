#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src,dest;
};

class Graph{
public:
	int V,E;
	Edge *edge;
	Graph(int v,int e){
		V=v;
		E=e;
		edge=new Edge[E];
	}
};

class subset{
public:
	int parent,rank;
};

int find(subset subsets[],int i){
	if(subsets[i].parent!=i){
		subsets[i].parent=find(subsets,subsets[i].parent);
	}
	return subsets[i].parent;
}

void Union(subset subsets[],int xroot,int yroot){
	if(subsets[xroot].rank<subsets[yroot].rank)
		subsets[xroot].parent=yroot;
	else if(subsets[xroot].rank>subsets[yroot].rank)
		subsets[yroot].parent=xroot;
	else{
		subsets[yroot].parent=xroot;
		subsets[xroot].rank++;
	}
}

bool isCycle(Graph *graph){
	int V=graph->V;
	int E=graph->E;
	subset subsets[V];
	for(int i=0;i<V;i++){
		subsets[i].parent=i;
		subsets[i].rank=0;
	}
	for(int i=0;i<E;i++){
		int x=find(subsets,graph->edge[i].src);
		int y=find(subsets,graph->edge[i].dest);
		if(x==y)
			return true;
		Union(subsets,x,y);
	}
	return false;
}

int main()
{
    /* Let us create the following graph
         0
        |  \
        |    \
        1-----2 */
 
    int V = 3, E = 3;
    Graph *graph=new Graph(V,E);
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        printf("Graph contains cycle");
    else
        printf("Graph doesn't contain cycle");
 
    return 0;
}