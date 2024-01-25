//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp (pair<double,Item> a , pair< double,Item> b)
    {
        return a.first > b.first;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector< pair<double,Item>> v;
        for(int i=0;i< n ;i++)
        {
            double perunitvalue=(double(arr[i].value))/arr[i].weight;
            pair<double, Item> p=make_pair(perunitvalue,arr[i]);
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),cmp);
        double total=0;
        for(int i=0;i<n;i++)
        {
            //agr current ki value total W se badi hai to hum uski sirf kuch fraction hii le payenge..
            if(v[i].second.weight > W)
            {
                total=total + W*v[i].first;
                W=0;
            }
            else{
                //vrna hum full item le payenge
                total=total+v[i].second.value;
                //second ki value kam ho ajyegi dusre ki weight se
                W=W-v[i].second.weight;
            }
            
        }
        return total;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends