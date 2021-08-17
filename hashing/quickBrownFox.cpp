#include<bits/stdc++.h>
using namespace std;

int bars(string s,unordered_set<string>&words,int idx){
    if(s[idx]=='\0')return 0;
    string temp="";
    int ans=INT_MAX;
    for(int i=idx;s[i]!='\0';i++){
        temp+=s[i]; 
        if(words.find(temp)!=words.end()){
            int remAns=bars(s,words,i+1);
            if(remAns!=-1)ans=min(ans,remAns+1);
        }
    }
    if(ans==INT_MAX)return -1;
    return ans;
}

int main(){
    string words[]={"the","quickbrown","fox","quick","brown"};
    string s="thequickbrownfox";
    unordered_set<string>m;
    for(string word:words){
        m.insert(word);
    }
    cout<<bars(s,m,0)-1<<endl;
}
