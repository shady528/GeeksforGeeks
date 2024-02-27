//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S=read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.DivisibleByEight(S));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    int DivisibleByEight(String s){
        //code here
        int y;
        if(s.length()>2){   //if digits in number is greater than 2,                                       //then we only pick last three numbers.
  y = Integer.parseInt(s.substring(s.length()-4));
        }else{
            y=Integer.parseInt("0"+s);  // otherwise we add zero                                                          //at starting , remeber that                                                  //we have add string "0". not 0;
        }
        if(y%8==0){
            return 1;
        }
        return -1;
    }
}