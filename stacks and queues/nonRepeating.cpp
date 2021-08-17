#include<iostream>
#include<queue>

using namespace std;

int main(){
	string s;
	cin>>s;
	queue<char>q;
	int freq[26]{0};
	for(char ch:s){
		q.push(ch);
		freq[ch-'a']++;
		while(!q.empty()){
			int i=q.front()-'a';
			if(freq[i]>1){
				q.pop();
			}
			else{
				cout<<q.front()<<' ';
				break;
			}
		}
		if(q.empty())
			cout<<-1<<' ';
	}
	cout<<endl;
}