#include<bits/stdc++.h>
using namespace std;
class Node{
	string city;
public:
	Node(string city){
		this->city=city;
	}
	list<string>nbrs;
};
class Graph{
	unordered_map<string,Node*>m;
public:
	Graph(vector<string>&cities){
		for(auto& city:cities){
			m[city]=new Node(city);
		}
	}
	void addEdge(string x,string y,bool undir=false){
		m[x]->nbrs.push_back(y);
		if(undir){
			m[y]->nbrs.push_back(x);
		}
	}
	void print(){
		for(auto cityPair:m){
			auto city=cityPair.first;
			Node *node=cityPair.second;
			cout<<city<<"--->";
			for(auto nbr:node->nbrs){
				cout<<nbr<<',';
			}
			cout<<endl;
		}
	}
};

int main(){
	vector<string>cities={"delhi","london","paris","new york"};
	Graph g(cities);
	g.addEdge("delhi","london");
	g.addEdge("new york","london");
	g.addEdge("delhi","paris");
	g.addEdge("paris","new york");
	g.print();
}