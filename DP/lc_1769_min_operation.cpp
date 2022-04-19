class Solution {
public:
    vector<int> minOperations(string s) {
        int n=s.size();
        vector<int>dp1(n,0);
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(i==0){
                if(s[i]=='1'){
                    cnt++;
                }
            }
            else{
                dp1[i]=dp1[i-1]+cnt;
                if(s[i]=='1'){
                    cnt++;
                }
            }
        }
        cnt=0;
        int cost=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                if(s[i]=='1'){
                    cnt++;
                }
            }
            else{
                dp1[i]+=(cost+cnt);
                cost=cost+cnt;
                if(s[i]=='1'){
                    cnt++;
                }
            }
        }
        return dp1;
    }
};