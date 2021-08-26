#include<bits/stdc++.h>
using namespace std;

int jumpGame(vector<int>&arr){
	int n=arr.size();
	int idx=0,reach=arr[0],count=0;
	for(int i=1;i<n;i++){
		if(reach>n)return count;
		if(arr[i]+i>reach){
			count++;
			reach=arr[i]+i;
		}
	}
	return count;
}


int main(){
	vector<int>arr={3,4,2,1,2,3,7,1,1,1,2,5};
	cout<<jumpGame(arr)<<endl;

}