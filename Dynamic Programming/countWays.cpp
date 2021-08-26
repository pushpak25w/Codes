#include<bits/stdc++.h>
using namespace std;

int countWaysRecur(int n,int k){
	if(n<0)return 0;
	if(n==0)return 1;
	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=countWaysRecur(n-i,k);
	}
	return ans;
}

int countWaysTD(int n,int k,int *dp){
	if(n<0)return 0;
	if(n==0)return 1;
	if(dp[n]!=0)return dp[n];
	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=countWaysTD(n-i,k,dp);
	}
	return dp[n]=ans;
}

int countWaysBU(int n,int k){
	vector<int>dp(n+1,0);
	dp[0]=1;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<k+1;j++){
			if(i-j>=0){
				dp[i]+=dp[i-j];
			}
		}
	}
	return dp[n];
}

int countWaysOpt(int n,int k){
	vector<int>dp(n+1,0);
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=k;i++){
		dp[i]=2*dp[i-1];
	}
	for(int i=k+1;i<=n;i++){
		dp[i]=2*dp[i-1]-dp[i-k-1];
	}
	return dp[n];
}
int main(){
	int n,k;
	cin>>n>>k;
	//int dp[n+1]{0};
	cout<<countWaysOpt(n,k)<<endl;
}