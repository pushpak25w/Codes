#include<iostream>
using namespace std;

void housing(int *plots,int n,int k){
	int currSum=0,i=0,j=0;
	while(i<n){
		currSum+=plots[i];
		while(currSum>k && j<=i){
			currSum-=plots[j];
			j++;
		}
		if(currSum==k)
			cout<<j<<"---"<<i<<endl;
		i++;
	}
}

int main(){
	int plots[]={1,3,2,1,4,1,3,2,1,1};
	int n=sizeof(plots)/sizeof(int);
	int k=8;
	housing(plots,n,k);
}