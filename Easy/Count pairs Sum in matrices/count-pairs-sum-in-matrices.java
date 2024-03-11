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
            String input[] = read.readLine().split(" ");
            
            int n = Integer.parseInt(input[0]);
            int x = Integer.parseInt(input[1]);
            
            int mat1[][] = new int[n][n];
            
            for(int i = 0;i<n;i++){
                input = read.readLine().split(" ");
                for(int j = 0;j<n;j++){
                    mat1[i][j] = Integer.parseInt(input[j]);
                }
            }
            
            int mat2[][] = new int[n][n];
            
            for(int i = 0;i<n;i++){
                input = read.readLine().split(" ");
                for(int j = 0;j<n;j++){
                    mat2[i][j] = Integer.parseInt(input[j]);
                }
            }
            
        
            
            Solution ob = new Solution();
            System.out.println(ob.countPairs(mat1,mat2,n,x));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    int countPairs(int mat1[][], int mat2[][], int n, int x) {
        // code here
        ArrayList<Integer> a1 = new ArrayList<>();
        ArrayList<Integer> a2 = new ArrayList<>();

        // Flatten the matrices and store them in sorted arrays
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a1.add(mat1[i][j]);
                a2.add(mat2[i][j]);
            }
        }

        // Sort the second array in reverse order
        Collections.sort(a2, Collections.reverseOrder());

        int count = 0;
        int i = 0;
        int j = 0;

        // Two-pointer approach to find pairs
        while (i < a1.size() && j < a2.size()) {
            int sum = a1.get(i) + a2.get(j);

            if (sum == x) {
                count++;
                i++;
                j++;
            } else if (sum < x) {
                i++;
            } else {
                j++;
            }
        }

        return count;
    }
}