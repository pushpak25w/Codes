#include<cstring>
#include<iostream>
#include<vector>

using namespace std;
int main(){
	char s[1000];
	cin.getline(s,1000);
	char *token=strtok(s," ");
	while(token!=NULL){
		cout<<token<<',';
		token=strtok(NULL," ");
	}
	cout<<endl;
}