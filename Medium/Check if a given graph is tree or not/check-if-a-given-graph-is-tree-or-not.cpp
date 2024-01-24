//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool isCycle(vector<vector<int>>& adj, vector<int>& vis, int n, int m, int node, int parent) {
        vis[node]=1;
        for (auto newNode : adj[node]) {
            if (!vis[newNode]) {
                if (!isCycle(adj, vis, n, m, newNode, node)) {
                    return false;
                }
            } else if (newNode != parent) {
                return false;
            }
        }
        return true;
    }

    int isTree(int n, int m, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    
        vector<int> vis(n,0);
        bool res = isCycle(adj, vis, n, m, 0, -1);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends