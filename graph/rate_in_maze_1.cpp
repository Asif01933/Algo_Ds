#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
vector<vector<int>>v(5000,vector<int>(5000));
int vis[5000][5000];
int n;
string dir="RDLU";
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y,string s){
    if(x==n-1 && y==n-1 && v[x][y]==1){
        ans.push_back(s);
        return;
    }
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=dx[i]+x;
        int yy=dy[i]+y;
        if(xx>=0 && yy>=0 && xx<n && yy<n && v[xx][yy]==1 && vis[xx][yy]==0){
            s+=dir[i];
            //cout<<xx<<" "<<yy<<" string: "<<s<<" "<<i<<endl;
            dfs(xx,yy,s);
            s.pop_back();
        }
    }
    vis[x][y]=0;
    return;

}
int main(){
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    if(v[0][0]==0){
        cout<<"-1"<<endl;
        return 0;
    }
    dfs(0,0,"");
    if(ans.size()==0){
        cout<<"-1"<<endl;
    }
    else{
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }
    
}