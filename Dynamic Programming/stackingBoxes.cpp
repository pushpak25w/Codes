#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<int>&a,vector<int>&b){
	return a[2]>b[2];
}

bool can_place(vector<int>&a,vector<int>&b){
	if(a[0]>b[0] && a[1]>b[1] && a[2]>b[2])
		return true;
	return false;
}

int stackingBoxes(vector<vector<int>>&dimensions){
	sort(dimensions.begin(),dimensions.end(),comp);
	int n=dimensions.size(),ans=0;
	vector<int>dp(n+1,0);
	for(int i=0;i<n;i++){
		dp[i]=dimensions[i][2];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(can_place(dimensions[j],dimensions[i])){
				int curr_height=dimensions[i][2];
				if(dp[j]+curr_height>dp[i])
					dp[i]=dp[j]+curr_height;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<dp[i]<<' ';
		ans=max(ans,dp[i]);
	}
	cout<<endl;
	return ans;
}

int main(){
	vector<vector<int>>boxes={
		{2,1,2},
		{3,2,3},
		{2,2,8},
		{2,3,4},
		{2,2,1},
		{4,4,5}
	};
	cout<<stackingBoxes(boxes)<<endl;
}