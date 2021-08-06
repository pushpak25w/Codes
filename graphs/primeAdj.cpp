#include<bits/stdc++.h>
using namespace std;

#define V 5

int minKey(int key[],bool mstSet[]){
	int min=INT_MAX,min_idx;
	for(int i=0;i<V;i++){
		if(mstSet[i]==false && key[i]<min){
			min=key[i];
			min_idx=i;
		}
	}
	return min_idx;
}

void printMst(int parent[],int graph[V][V]){
	for(int i=1;i<V;i++){
		cout<<parent[i]<<'-'<<i<<'\t'<<graph[i][parent[i]]<<endl;
	}
}

void primMst(int graph[V][V]){
	int parent[V];
	int key[V];
	bool mstSet[V];
	for(int i=0;i<V;i++){
		key[i]=INT_MAX;
		mstSet[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	for(int i=0;i<V-1;i++){
		int u=minKey(key,mstSet);
		mstSet[u]=true;
		for(int j=0;j<V;j++){
			if(graph[u][j] && mstSet[j]==false && graph[u][j]<key[j]){
				key[j]=graph[u][j];
				parent[j]=u;
			}
		}
	}
	printMst(parent,graph);
}
int main()
{
    /* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | / \ |
    (3)-------(4)
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    primMst(graph);
 
    return 0;
}