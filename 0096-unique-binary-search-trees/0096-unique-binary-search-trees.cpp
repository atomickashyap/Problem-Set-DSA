class Solution {
private:
    int solver(int n,vector<int>&dp)
    {
        if(n<=1)
            return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 1;i<=n;i++)
        {
            ans+= solver(i-1,dp)*solver(n-i,dp);
        }
        return dp[n] = ans;
    }
    int solvertab(int n)
    {
        vector<int> dp(n+1,0);
        dp[0] = dp[1] = 1;
        
        for(int i = 2;i<=n;i++)
        {
            // i->no. of nodes
            for(int j = 1;j<=i;j++)
            {
                //j = ->root node
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
public:
    int numTrees(int n) {
        // vector<int>dp(n+1,-1);
        // return solver(n,dp);
        return solvertab(n);
    }
};