#include<bits/stdc++.h>
using namespace std;
int n,e;
vector<int>g[500000];
bool vis[500000];
int par[500000];
bool dfs(int u,int p){
    vis[u]=true;
    for(auto v:g[u]){
        if(vis[v]==false){
            if(dfs(v,u)){
                return true;
            }
        }
        else if(v!=p){
            return true;
        }
    }
    return false;
}
bool is_cyclic(){
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++){
        if(vis[i]==false && dfs(i,-1)){
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(is_cyclic()){
        cout<<"cyclic"<<endl;
    }
    else{
        cout<<"asyclic"<<endl;
    }

}