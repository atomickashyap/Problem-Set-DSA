//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
    int n = s.length();
    int len=1;
    
    vector<vector<int>>dp(n,vector<int>(n));
    for(int i=0;i<n;i++)dp[i][i]=1;
    
    for(int i=0;i<n-1;i++)if(s[i]==s[i+1]){len=2;dp[i][i+1]=1;}
    
    int start=0;
    for(int i=3;i<=n;i++){
        //check for palindromic substring of length i
        for(int j=0;j<=(n-i);j++){
            int end=j+i-1;
          
            if(dp[j+1][end-1]&&s[j]==s[end]){
                if(i>len){
                len=i;
                start=j;}
                dp[j][end]=1;
            }
        }
    }
    if(len==1){string temp="";temp+=s[0];return temp;}
    if(len==2){
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                string res="";
                res+=s[i];
                res+=s[i+1];
                return res;
            }
        }
    }
    return s.substr(start,len);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends