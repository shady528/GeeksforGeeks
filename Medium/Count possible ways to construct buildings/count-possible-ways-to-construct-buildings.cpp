//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    int mod = 1e9+7;
	     long long int f1=2,f2=3,nxt=0;
        if(N<3) return pow(N+1,2);
        for(int i=3;i<N+1;i++){
            nxt=(f1+f2)%mod;
            f1=f2;
            f2=nxt;
        }
       return (nxt*nxt)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends