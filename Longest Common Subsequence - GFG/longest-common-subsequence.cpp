//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence
static int t[1003][1003];
class Solution
{
    private:
    int mem(int n,int m,string &s1,string &s2)
    {
        if(n==0||m==0)
        {
            return 0;
        }
        
        if(t[n][m] !=-1)
        {
            return t[n][m];
        }
        if(s1[n-1] == s2[m-1])
        {
            return t[n][m] = 1+mem(n-1,m-1,s1,s2);
        }
        else{
            return t[n][m] = max(mem(n-1,m,s1,s2),mem(n,m-1,s1,s2));
        }
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        // vector<vector<int>> t(n+1,vector<int>(m+1,-1));
        memset(t,-1,sizeof(t));
        return mem(n,m,s1,s2);
        // return t[n][m];
        
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends