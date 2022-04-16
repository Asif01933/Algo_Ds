#include<bits/stdc++.h>
using namespace std;
int dis[1002][1002];
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
int main(){

    int n;
    cin>>n;
    int x,y,fx,fy;
    cin>>x>>y>>fx>>fy;
    dis[x][y]=0;
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        auto u=q.front().first;
        auto v=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int xx=u+dx[i];
            int xy=v+dy[i];
            if(xx>0 && xx<=n && xy<=n && xy>0 && dis[xx][xy]==0){
                dis[xx][xy]=1+dis[u][v];
                q.push({xx,xy});
            }
        }
    }
    cout<<dis[fx][fy]<<endl;


}