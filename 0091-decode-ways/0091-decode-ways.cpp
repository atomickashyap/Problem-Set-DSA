class Solution {
private:
    int n = 0;
    
    int helper(string &s,int pos,vector<int> &dp)
    {
        if(pos == n)    return 1;
        if(s[pos] == '0') return 0;
        if(dp[pos] != -1) return dp[pos];
        int count = helper(s,pos+1,dp);
        if(pos<n-1 && s.substr(pos,2)<"27")
        {
            count+=helper(s,pos+2,dp);
        }
        return dp[pos] = count;
    }
public:
    int numDecodings(string s) {
        n = s.length();
        vector<int> dp(n+1,-1);
        return helper(s,0,dp);
    }
};