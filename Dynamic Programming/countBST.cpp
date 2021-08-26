#include <bits/stdc++.h>
using namespace std;

int countBSTrecur(int n){
	if(n==0 || n==1)return 1;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=countBSTrecur(i-1);
		int y=countBSTrecur(n-i);
		ans+=x*y;
	}
	return ans;
}

int countBSTtd(int n,vector<int>&dp){
	if(n==0 || n==1)return 1;
	if(dp[n]!=0)return dp[n];
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=countBSTtd(i-1,dp);
		int y=countBSTtd(n-i,dp);
		ans+=x*y;
	}
	return dp[n]=ans;
}

int countBSTbu(int n){
	vector<int>dp(n+1,0);
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i]+=dp[j-1]*dp[i-j];
		}
	}
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	// cout<<countBSTrecur(n)<<endl;
	// vector<int>dp(n,0);
	// cout<<countBSTtd(n,dp)<<endl;
	cout<<countBSTbu(n)<<endl;
}