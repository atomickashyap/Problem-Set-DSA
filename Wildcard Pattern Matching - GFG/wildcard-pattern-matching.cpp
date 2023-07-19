//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
/*You are required to complete this method*/
    
    bool fun(int i,int j,string &str,string &pat,vector<vector<int>> &dp)
    {
        if(i<0 && j<0) 
            return true;
        if(i<0 && j>=0)
            return false;
        if(j<0 && i>=0)
        {
            for(int k=0;k<=i;k++)
                if(pat[k]!='*')
                    return false;
            return true;
        }
        if(dp[i][j]!=-1) 
            return dp[i][j];
        if(str[j]==pat[i] || pat[i]=='?')
            return dp[i][j]=fun(i-1,j-1,str,pat,dp);
        if(pat[i]=='*')
        {
            return dp[i][j]=(fun(i-1,j,str,pat,dp) || fun(i,j-1,str,pat,dp));
        }
        return dp[i][j]=false;
    }
    
    int wildCard(string pattern,string str)
    {
        int n1=pattern.length();
        int n2=str.length();
        
        vector<vector<int>> dp(201,vector<int>(201,-1));
        
        return fun(n1,n2,str,pattern,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends