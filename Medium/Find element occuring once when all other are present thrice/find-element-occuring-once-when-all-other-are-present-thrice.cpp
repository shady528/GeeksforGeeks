//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        vector<int> v(32, 0);
        
        for(int i = 0; i < N; ++i) {
            bitset<32> a(arr[i]);
            for(int i = 0; i < 32; i++) v[i] += a[i];
        }
        
        int pow2 = 1, res = 0;
        for(int i = 0; i < 32; i++) {
            // didn't occur thrice, then add it to ans
            if(v[i] % 3 != 0)    res += pow2;
            pow2 *= 2;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends