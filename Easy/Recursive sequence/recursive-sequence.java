//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int N = Integer.parseInt(in.readLine());
            
            Solution ob = new Solution();
            System.out.println(ob.sequence(N));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static long sequence(int n){
        // code here
        long ct=1;
        long sum=0;
        long temp=1;
        long number=1;
        while(number<=n)
        {
            for(int i=0;i<number;i++)
            {
                temp=(ct*temp)%1000000007;
                ct++;
                
            }
            
            sum=(sum+temp)%1000000007;
          
           temp=1;
            
            
            number++;
        }
        return sum%1000000007;
    }
}