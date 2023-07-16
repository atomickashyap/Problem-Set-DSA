//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string str1, string str2, int n, int m)
    {
        //code here
        //  int n =  str1.length();
        // int m = str2.length();
        
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        
        for(int i =1;i<n+1;i++)
        {
            for(int j = 0;j<m+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    t[i][j] = t[i-1][j-1] +1;
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return (n+m)-t[n][m];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends