#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void sortposneg(int arr[],int n){
	int r=n-1,i=0;
	while(r>i){
		if(arr[i]>0){
			while(arr[r]>0 && r>i)r--;
			swap(arr[i],arr[r--]);
		}
		i++;
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sortposneg(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
}

