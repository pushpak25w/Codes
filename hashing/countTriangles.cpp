#include<bits/stdc++.h>
using namespace std;

int countTriangles(vector<pair<int,int>>points){
    unordered_map<int,int>x;
    unordered_map<int,int>y;
    for(auto point:points){
        x[point.first]++;
        y[point.second]++;
    }
    int count=0;
    for(auto point:points){
        count+=(x[point.first]-1)*(y[point.second]-1);
    }
    return count;
}

int main(){
    int n,x,y;
    cin>>n;
    vector<pair<int,int>>points;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        points.push_back({x,y});
    }
    cout<<countTriangles(points)<<endl;
}
