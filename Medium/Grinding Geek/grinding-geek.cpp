//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int f(int ind , int total , vector<int>&cost,vector<vector<int>>&dp){
        if(ind>=cost.size()) return 0 ;
        if(total==0)return 0 ;
        if(dp[ind][total]!=-1) return dp[ind][total] ;
        int take=0  , nottake=0 ;
       if(total-cost[ind]>=0) take =1+f(ind +1 , total-cost[ind]+floor(cost[ind]*0.9) , cost,dp) ;
        nottake = 0+f(ind+1 , total , cost,dp) ;
        return dp[ind][total] = max(take, nottake) ;
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        // resultant_money after 1 purchase= total- cost[i]+ floor (cost[i]*0.9)
        vector<vector<int>>dp(n+1 , vector<int>(total+1 , -1)) ;
        return f(0 , total, cost,dp) ;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends