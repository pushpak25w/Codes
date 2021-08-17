#include<bits/stdc++.h>
using namespace std;
class Point{
public:
    int x,y;
    Point(){
        
    }
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
};
class compare{
    public:
    bool operator()(const Point p1,const Point p2){
        if(p1.x==p2.x)return p1.y<p2.y;
        return p1.x<p2.x;
    }
};
int countRectangles(vector<Point>&points){
    set<Point,compare >check;
    for(Point p:points){
        check.insert(p);
    }
    int count=0;
    for(auto it=check.begin();it!=prev(check.end());it++){
        for(auto jt=next(it);jt!=check.end();jt++){
            Point p1=*it;
            Point p2=*jt;
            if(p1.x==p2.x || p1.y==p2.y)
                continue;
            Point p3(p1.x,p2.y);
            Point p4(p2.x,p1.y);
            if(check.find(p3)!=check.end() && check.find(p4)!=check.end()){
                count++;
            }
        }
    }
    return count/2;
}

int main(){
  int n,x,y;
  cin>>n;
  vector<Point>points;
  for(int i=0;i<n;i++){
      cin>>x>>y;
      Point p(x,y);
      points.push_back(p);
  }
  cout<<countRectangles(points)<<endl;
}
