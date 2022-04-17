class Solution {
public:
    void dfs(int i,vector<bool>&vis,vector<vector<int>>&adj){
        vis[i]=true;
        for(auto v:adj[i]){
            if(vis[v]==0){
                dfs(v,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& g) {
        if(g.size()<n-1){
            return -1;
        }
        vector<vector<int>>adj(n);
        vector<bool>vis(n,0);
        for(auto v:g){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans-1;
    }
};