class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
        int n = x.length(),m = y.length();
        vector<vector<int>> t(n+1,vector<int>(m+1,0));
        
        for(int  i =1;i<n+1;i++)
        {
            for(int j = 1;j<m+1;j++)
            {
                if(x[i-1] == y[j-1])
                {
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        
        
        return t[n][m];
        
    }
};