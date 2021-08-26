#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int>&arr){
	int n=arr.size();
	for(int i=2;i<n;i++){
		arr[i]=max(arr[i-1],arr[i]+arr[i-2]);
	}
	return arr[n-1];
}

int main(){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<maxSum(arr)<<endl;
}