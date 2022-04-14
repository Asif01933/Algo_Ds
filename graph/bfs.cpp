//bfs code
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int>q;
    bool vis[n+1];
    for(int i=0;i<n+1;i++){
        vis[i]=false;
    }
    int s;
    cin>>s;
    q.push(s);
    vis[s]=true;

    while(!q.empty()){
        auto x=q.front();
        cout<<x<<" ";
        q.pop();
        for(auto y:g[x]){
            if(vis[y]==false){
                vis[y]=true;
                q.push(y);
            }
        }
    }
    //
    return 0;
}
