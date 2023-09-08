//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    private:
    int mem(int W, int wt[], int val[], int n,vector<vector<int>>&t)
    {
        for(int i =1;i<n+1;i++)
        {
            for(int j =1;j<W+1;j++)
            {
                if(wt[i-1]<=j)
                {
                    t[i][j] =max(val[i-1]+ t[i-1][j-wt[i-1]], t[i-1][j]);
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
                
            }
        }
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        vector<vector<int>> T(n+1,vector<int>(W+1,0));
        mem(W,wt,val,n,T);
        return T[n][W];
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends