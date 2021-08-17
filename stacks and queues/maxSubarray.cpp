#include<iostream>
#include<deque>
using namespace std;

int main(){
	int n,k;
	cin>>n;
	int arr[n+1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>k;
	int i=0;
	deque<int>q(k);
	for(;i<k;i++){
		while(!q.empty() && arr[i]>arr[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
	}
	for(;i<n;i++){
		cout<<arr[q.front()]<<' ';
		while(!q.empty() && q.front()<=i-k){
			q.pop_front();
		}
		while(!q.empty() && arr[i]>=arr[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
	}

}
