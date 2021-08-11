#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

string extractStringAtKey(string str,int key){
	char *s=strtok((char*)str.c_str()," ");
	while(key>1){
		s=strtok(NULL," ");
		key--;
	}
	return (string)s;
}

int convertToInt(string a){
	int ans=0,p=1;
	for(int i=a.length()-1;i>=0;i++){
		ans+=((a[i]-'0')*p);
		p=p*10;
	}
	return ans;
}

bool numericComp(pair<string,string>&a,pair<string,string>&b){
	return convertToInt(a.second)<convertToInt(b.second);
}

bool lexicoComp(pair<string,string>&a,pair<string,string>&b){
	return a.second<b.second;
}

int main(){
	int n;
	cin>>n;
	cin.get();
	string temp;
	vector<string>input;
	for(int i=0;i<n;i++){
		getline(cin,temp);
		input.push_back(temp);
	}
	int key;
	string reversal,ordering;
	cin>>key>>reversal>>ordering;
	vector<pair<string,string>>strs;
	for(int i=0;i<n;i++){
		strs.push_back({input[i],extractStringAtKey(input[i],key)});
	}
	if(ordering=="numeric"){
		sort(strs.begin(),strs.end(),numericComp);
	}
	else{
		sort(strs.begin(),strs.end(),lexicoComp);
	}
	if(reversal=="true"){
		reverse(strs.begin(),strs.end());
	}
	for(int i=0;i<n;i++){
		cout<<strs[i].first<<endl;
	}
	return 0; 
}