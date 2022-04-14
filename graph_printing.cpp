#include<bits/stdc++.h>
using namespace std;
int main(){

    //adjacency matrix
    int n,m;
    cin>>n>>m;
    int g[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            g[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u][v]=1;
        g[v][u]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------------"<<endl;

    //adjacency matrix
    int r,c;
    cin>>r>>c;
    vector<int>graph[r];
    for(int i=0;i<c;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<c;i++){
        cout<<i<<" -> ";
        for(auto x:graph[i]){
            cout<<x<<", ";
        }
        cout<<endl;
    }
    return 0;
}
