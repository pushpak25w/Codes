#include<bits/stdc++.h>
using namespace std;

int matrixChain(int *arr,int i,int j){
	if(i==j)return 0;
	int k,count,mini=INT_MAX;
	//recursive calls to subproblems
	for(int k=i;k<j;k++){
		count=matrixChain(arr,i,k)+matrixChain(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		mini=min(count,mini);
	}
	return mini;
}
int dp[100][100];
int matrixChainmemo(int* arr,int i,int j){
	if(i==j)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	dp[i][j]=INT_MAX;
	for(int k=i;k<j;k++){
		dp[i][j]=min(dp[i][j],
			matrixChainmemo(arr,i,k)+matrixChainmemo(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
	}
	return dp[i][j];
}

int matrixChaintab(int *arr,int n){
	int dp[n][n]{0};
	for(int l=2;l<n;l++){
		for(int i=1;i<n-l+1;i++){
			int j=i+l-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
			}
		}
	}
	return dp[1][n-1];
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Minimum number of multiplications is "
         << matrixChain(arr, 1, n - 1)<<endl;
    memset(dp,-1,sizeof(dp));
    cout << "Minimum number of multiplications is "
         << matrixChainmemo(arr, 1, n - 1)<<endl;
	cout << "Minimum number of multiplications is "
         << matrixChaintab(arr,n)<<endl;
}