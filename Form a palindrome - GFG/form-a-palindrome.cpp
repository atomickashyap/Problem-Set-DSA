//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string a){
        // code here 
        string b = a;
        reverse(b.begin(),b.end());
        int n = a.length(), m = b.length();
        vector<vector<int>> t(n+1,vector<int>(m+1,0));
        
        
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<m+1;j++)
            {
                if(a[i-1] == b[j-1])
                {
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return n-t[n][m];
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends