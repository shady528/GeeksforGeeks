//{ Driver Code Starts
//Initial Template for Java



import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            String[] inputLine = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            System.out.println(new Solution().sumBitDifferences(arr, n));
        }
    }
}

// } Driver Code Ends


//User function Template for Java



class Solution {
    long sumBitDifferences(int[] arr, int n) {
        // code here
        long sum = 0;
        
        for(int i=0; i<32; i++){
            long setBitsCount = 0;
            long unsetBitsCount = 0;
            
            for(int num : arr){
                if((num & (1 << i)) == 0){
                    unsetBitsCount++;
                }
                else{
                    setBitsCount++;
                }
            }
            
            sum += setBitsCount * unsetBitsCount;
        }
        
        return 2*sum;
    }
}