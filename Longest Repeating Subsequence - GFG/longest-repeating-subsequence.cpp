//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string a){
		    // Code here
		    string b = a;
		    int n= a.length(),m = b.length();
		    
		    vector<vector<int>>t(n+1,vector<int>(m+1,0));
		    for(int i = 1;i<n+1;i++)
		    {
		        for(int j = 1;j<m+1;j++)
		        {
		            if(a[i-1] == b[j-1] && i!=j)
		            {
		                t[i][j] = t[i-1][j-1]+1;
		            }
		            else{
		                t[i][j] = max(t[i-1][j],t[i][j-1]);
		            }
		        }
		    }
            return t[n][m];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends