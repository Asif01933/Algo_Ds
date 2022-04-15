#include<bits/stdc++.h>
using namespace std;
int col[500000];
vector<int>g[500000];
int n,e,ok;
bool dfs(int u){
    col[u]=1;
    for(auto v:g[u]){
        if(col[v]==0 && dfs(v)){
            return true;
        }
        else if(col[v]==1){
            return true;
        }
    }
    col[u]=2;
    return false;
}
bool is_cyclic(){
    memset(col,0,sizeof(col));
    for(int i=0;i<n;i++){
        if(col[i]==0 && dfs(i)){
            return true;
        }
    }
    return false;

}
int main(){
    
    cin>>n>>e;
    int u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        g[u].push_back(v);
    }
    if(is_cyclic()){
        cout<<"cyclic"<<endl;
    }
    else{
        cout<<"acyclic"<<endl;
    }
    
    return 0;
}