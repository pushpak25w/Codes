#include<bits/stdc++.h>
using namespace std;

void replace_str(char *str){
	int spaces=0;
	for(int i=0;str[i]!='\0';i++){
		if(str[i]==' ')spaces++;
	}
	int idx=strlen(str)+2*spaces;
	str[idx]='\0';
	for(int i=strlen(str)-1;i>=0;i--){
		if(str[i]==' '){
			str[idx--]='0';
			str[idx--]='2';
			str[idx--]='%';
		}
		else{
			str[idx--]=str[i];
		}
	}
}

int main(){
	char s[10000];
	cin.getline(s,1000);
	replace_str(s);
	cout<<s<<endl;
	return 0;
}