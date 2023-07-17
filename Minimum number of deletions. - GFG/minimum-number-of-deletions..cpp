//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string a, int n) { 
    //complete the function here 
    
    
    string b = a;
    reverse(b.begin(),b.end());
    int m =n;
    vector<vector<int>> t(n+1,vector<int>(m+1,0));
    
    for(int i = 1;i<n+1;i++)
    {
        for(int j = 1;j<m+1;j++)
        {
            if(a[i-1] == b[j-1])
            {
                t[i][j] = t[i-1][j-1]+1;
                
            }
            else{
                t[i][j] = max(t[i][j-1],t[i-1][j]);
            }
        }
    }
    return n-t[n][m];
} 