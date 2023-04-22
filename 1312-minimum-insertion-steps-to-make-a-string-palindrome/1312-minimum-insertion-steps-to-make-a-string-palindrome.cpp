class Solution {
public:
    int memo[501][501];
    int minInsertions(string s) {
        for(int i = 0; i < 501; i++)
            for(int j = 0; j < 501; j++)
                memo[i][j] = -1;
        return dp(s, 0, s.size() - 1);
    }
    int dp(string& s, int i, int j){
        if(i >= j)
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];
        return memo[i][j] = s[i] == s[j] ? dp(s, i + 1, j - 1) : 1 + min(dp(s, i + 1, j), dp(s, i, j - 1));
    }
};