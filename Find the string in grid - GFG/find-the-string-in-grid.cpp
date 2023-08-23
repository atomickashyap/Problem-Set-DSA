//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool check(vector<vector<char>> &a,int m,int n,int i,int j,string &s,int k,int l,int di,int dj)
    {
        if(k==l)
        return 1;
        
        if(i>=0 && j>=0 && i<m && j<n && a[i][j]==s[k])
        return check(a,m,n,i+di,j+dj,s,k+1,l,di,dj);
        
        return 0;
    }

	vector<vector<int>>searchWord(vector<vector<char>>a, string s){
	    // Code here
	    int m=a.size(),n=a[0].size();
	    int i,j;
	    int di[]={-1,-1,-1,0,0,1,1,1};
        int dj[]={-1,0,1,-1,1,-1,0,1};
	    vector<vector<int>> ans;
	    
	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            if(a[i][j]==s[0])
	            {
	                for(int k=0;k<8;k++)
	                {
	                    if(check(a,m,n,i,j,s,0,s.length(),di[k],dj[k]))
	                    {
	                        ans.push_back({i,j});
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends