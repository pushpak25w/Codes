#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums){
    int n=nums.size();
    pair<int,int>numsWidx[n];
    for(int i=0;i<n;i++){
        numsWidx[i].first=nums[i];
        numsWidx[i].second=i;
    }
    sort(numsWidx,numsWidx+n);
    vector<bool>visited(n,false);
    int ans=0;
    for(int i=0;i<n;i++){
        int oldPos=numsWidx[i].second;
        if(oldPos==i || visited[i])continue;
        int node=i;
        int cycle=0,next;
        while(!visited[node]){
            visited[node]=true;
            next=numsWidx[node].second;
            node=next;
            cycle++;
        }
        ans+=(cycle-1);
    }
    return ans;
}

int main(){
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(3);
    cout<<minSwaps(nums)<<endl;

}
