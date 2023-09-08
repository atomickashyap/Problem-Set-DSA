//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long expo = 1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>t(n+1,vector<int >(sum+1,0));
        for(int i =0;i<n+1;i++)
        {
            t[i][0] = 1;
        }
        for(int i =1;i<n+1;i++)
        {
            for(int j =0;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j] = t[i-1][j-arr[i-1]]%expo + t[i-1][j] %expo;
                }
                else{
                    t[i][j] = t[i-1][j] %expo;
                }
            }
            
        }
        return t[n][sum] % expo;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends