//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String s = in.readLine();
            int k = Integer.parseInt(in.readLine());
            
            Solution ob = new Solution();
            System.out.println(ob.minValue(s, k));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution{
    static int minValue(String s, int k){
        // code here
        int arr[] = new int[26];
        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            int idx = ch - 'a';
            arr[idx]++;
        }
        int j = arr.length;
        for(int i=0; i<k; i++){
            Arrays.sort(arr);
            if(k>0){
                arr[j-1]--;
            }
        }
        int sum = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i] > 0){
                sum += arr[i]*arr[i];
            }
        }
        return sum;
    }
}