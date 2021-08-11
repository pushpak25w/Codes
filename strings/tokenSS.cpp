#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	stringstream ss(s);
	string token;
	vector<string>tokens;
	while(getline(ss,token,' ')){
		tokens.push_back(token);
	}
	for(auto token:tokens){
		cout<<token<<','; 
	}
	cout<<endl;
}