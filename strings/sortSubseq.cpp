#include<iostream>
#include <algorithm>
#include<vector>
#include <cstring>
using namespace std;
vector<string>strs;

void sortSubsequences(string s,string prev){
	if(s.size()==0){
		strs.push_back(prev);
		return;
	}
	char ch=s[0];
	string newS=s.substr(1);
	sortSubsequences(newS,prev+ch);
	sortSubsequences(newS,prev);
}

bool compare(string a,string b){
	if(a.size()==b.size()){
		return a<b;
	}
	return a.size()<b.size();
}

int main(){
	string s;
	cin>>s;
	sortSubsequences(s,"");
	sort(strs.begin(),strs.end(),compare);
	for(auto str:strs){
		cout<<str<<',';
	}

}