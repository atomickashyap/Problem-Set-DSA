class Solution {
private:
    int func(int i ,int j,string &str1, string &str2,vector<vector<int>> &dp)
    {
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j] !=-1)
            return dp[i][j];
        if(str1[i] == str2[j])
            return dp[i][j] = 0 + func(i-1,j-1,str1,str2,dp);
        return dp[i][j] = 1+min(func(i-1,j-1,str1,str2,dp),min(
                    func(i-1,j,str1,str2,dp),func(i,j-1,str1,str2,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int i = word1.length(),j = word2.length();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        return func(i-1,j-1,word1,word2,dp);
    }
};