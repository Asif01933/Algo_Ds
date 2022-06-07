//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        
        unordered_map<int,int>st;
        int sum=0,mx=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==0){
                mx=max(mx,i+1);
            }
            else{
                if(st.find(sum)!=st.end()){
                    mx=max(mx,i-st[sum]);
                }
                else{
                    st[sum]=i;
                }
            }
        }
        return mx;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends