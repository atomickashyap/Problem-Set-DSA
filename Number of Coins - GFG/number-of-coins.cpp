//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int amt) 
	{ 
	    // Your code goes here
	    int t[n+1][amt+1];
	    for(int i = 0;i<n+1;i++)
        {
            for(int j = 0;j<amt+1;j++)
            {
                if(j==0)
                    t[i][j] = 0;
                if(i==0)
                    t[i][j] = INT_MAX-1;
            }
        }   
	        
	        for(int j = 1;j<amt+1;j++)
            {
                int temp = coins[0];
                if(j%temp == 0)
                    t[1][j] = j/temp;
                else
                    t[1][j] = INT_MAX-1;
            }
	        
	        for(int i =2;i<n+1;i++)
	        {
	            for(int j = 1;j<amt+1;j++)
	            {
	                if(coins[i-1]<=j)
	                {
	                    t[i][j] = min(1+t[i][j-coins[i-1]], t[i-1][j]);
	                }
	                else
	                    t[i][j] = t[i-1][j];
	            }
	        }
	   return (t[n][amt]==(INT_MAX-1))? -1:t[n][amt];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends