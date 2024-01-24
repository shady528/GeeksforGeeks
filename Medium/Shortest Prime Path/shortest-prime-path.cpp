//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

vector<bool> isPrime(10000, true);

void sieve()
{
   for(int i =2; i*i<10000; ++i)
   {
       if(isPrime[i])
       {
           for(int j =  i*i; j<10000; j+=i)
           isPrime[j] = false;
       }
   }
}
class Solution{   
public:

 

   int solve(int a,int b)
   {   
     //code here
     if(a==b)
     return 0;
     sieve();
     
     queue<int> q;
     q.push(a);
     int ans = 0 ;
     vector<bool> visited(10000, false);
     visited[a] =  true;
     while(!q.empty())
     {
         queue<int> t;
         while(!q.empty())
         {
             int x = q.front();
             q.pop();
             if(x==b)
             return ans;
             for(int i = 0; i<4; ++i)
             {
                 if(i==0)
                 {
                     for(int j = 1; j<10; ++j)
                     {
                         string str = to_string(x);
                         str[i] = j+'0';
                         int temp = stoi(str);
                         if(temp==b)
                         return ans+1;
                         if( isPrime[temp] && visited[temp] == false)
                         {
                             visited[temp] = true;
                             t.push(temp);
                             
                         }
                     }
                 }
                 else
                 {
                     for(int j = 0; j<10; ++j)
                     {
                         string str = to_string(x);
                         str[i] = j+'0';
                         int temp = stoi(str);
                         if(temp ==b)
                         return ans+1;
                         if( isPrime[temp] && visited[temp] == false)
                         {
                             visited[temp] = true;
                             t.push(temp);
                             
                         }
                     }
                     
                 }
             }
             
         }
         q = t;
         
         ++ans;
     }

     return ans;
   }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends