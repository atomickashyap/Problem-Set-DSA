//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int dfs(int a,int b,vector<vector<int>>& vis,vector<vector<char>>& board,int ind,string word)
    {
        int len=word.length();
        vis[a][b]=1;
        if(ind==len)
        return 1;
        int i,row[4]={1,-1,0,0},col[4]={0,0,-1,1},n=board.size(),m=board[0].size();
        for(i=0;i<4;i++)
        {
            int r=a+row[i],c=b+col[i];
            if(r>=0&&r<n&&c>=0&&c<m&&vis[r][c]==0&&board[r][c]==word[ind])
            {
                int p=dfs(r,c,vis,board,ind+1,word);
                if(p==1)
                return 1;
            }
        }
        vis[a][b]=0;
        return 0;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int i,j,ind=0,n=board.size(),m=board[0].size(),len=word.length();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(vis[i][j]==0&&board[i][j]==word[ind])
                {
                    int p=dfs(i,j,vis,board,ind+1,word);
                    if(p==1)
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends