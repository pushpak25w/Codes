#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr,int s,int e){
	int mid=(s+e)/2;
	int i=s,j=mid+1;
	vector<int>temp;
	while(i<=mid && j<=e){
		if(arr[i]>arr[j]){
			temp.push_back(arr[j]);
			j++;
		}
		else{
			temp.push_back(arr[i]);
			i++;
		}
	}
	while(i<=mid){
		temp.push_back(arr[i]);
		i++;
	}
	while(j<=e){
		temp.push_back(arr[j]);
		j++;
	}
	int k=0;
	for(i=s;i<=e;i++){
		arr[i]=temp[k++];
	}
}

void mergesort(vector<int>&arr,int s,int e){
	if(s>=e)return;
	int mid=(s+e)/2;
	mergesort(arr,s,mid);
	mergesort(arr,mid+1,e);
	merge(arr,s,e);
}

int main(){
	vector<int>arr{10,5,2,0,7,6,4};
	int s=0,e=arr.size()-1;
	mergesort(arr,s,e);
	for(int x:arr){
		cout<<x<<' ';
	}
	cout<<endl;
}