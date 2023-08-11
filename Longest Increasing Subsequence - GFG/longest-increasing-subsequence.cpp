//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>lis;
       lis.push_back(a[0]);
       for(int i=1; i<n; i++){
           if(a[i]>lis.back()){
               lis.push_back(a[i]);
           }
           else{
            //   int index = lower_bound(lis.begin(),lis.end(),a[i]);
               auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            int index = it - lis.begin(); // Convert iterator to index
               lis[index] = a[i];
           }
       }
       return lis.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends