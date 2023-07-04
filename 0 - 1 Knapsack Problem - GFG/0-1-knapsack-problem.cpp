//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int t[1002][1002];

class Solution
{   
    private:
    int recur(int W,int wt[],int val[],int n)
    {
        if(W == 0|| n ==0)
        {
            return 0;
        }
        
        if(t[n][W] != -1)
            return t[n][W];
        
        if(wt[n-1] <= W)
        {
            return t[n][W] = max(val[n-1]+ recur(W - wt[n-1], wt,val,n-1)
                ,recur(W, wt,val,n-1));
        }
        else if(wt[n-1] > W){
            return t[n][W] =  recur(W, wt,val,n-1);
        }
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(t,-1,sizeof(t));
        return recur(W,wt,val,n);
        // return 0;
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