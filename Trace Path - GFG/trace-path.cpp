//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        // code
        int up=0,down=0,left=0,right=0,x=0,y=0;
        for(auto c:s){
            if(c=='L')
            x--;
            else if(c=='R')
            x++;
            else if(c=='U')
            y++;
            else
            y--;
            up=max(up,y);
            down=min(down,y);
            left=min(left,x);
            right=max(right,x);
        }
        return (up-down<n)&&(right-left)<m;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends