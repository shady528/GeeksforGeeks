//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void find(int N,vector<string>&ans,string temp,int one,int zero)
    {
        if(temp.size()==N)
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back('1');
        find(N,ans,temp,one+1,zero);
        temp.pop_back();
        
        if(zero<one)
        {
            temp.push_back('0');
            find(N,ans,temp,one,zero+1);
            temp.pop_back();
        }
        
    }
    vector<string> NBitBinary(int N)
    {
        vector<string>ans;
        string temp;
        find(N,ans,temp,0,0);
        return ans;

  // Your code goes here
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends