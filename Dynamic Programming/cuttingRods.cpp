#include <bits/stdc++.h>
using namespace std;

int cuttingRodsRecurr(int n, vector<int>&prices){
	if(n<=0)return 0;
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
		int cut=i+1;
		int curr_ans=prices[i]+cuttingRodsRecurr(n-cut,prices);
		ans=max(ans,curr_ans);
	}
	return ans;
}

int cuttingRodsBU(int n,vector<int>prices){
	vector<int>dp(n+1);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int curr_ans=INT_MIN;
		for(int j=0;j<i;j++)
			curr_ans=max(curr_ans,prices[j]+dp[i-j-1]);
		dp[i]=curr_ans;
	}
	return dp[n];
}


int main(){
	vector<int>prices={3,5,8,9,10,17,17,20};
	cout<<cuttingRodsBU(8,prices);


}