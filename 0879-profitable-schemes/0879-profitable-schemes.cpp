class Solution {
    private:
    int mod = 1e9+7;
    int cm = 1000+1;
    int solve(int n,vector<int>&g,vector<int>&p,int i,int minp,int dp[101][101][101]){
        if(i>=g.size()){if(minp<=0)return 1;return 0;}
        if(dp[i][n][max(0,minp)]!=-1)return dp[i][n][max(0,minp)];
        long long ans = 0;
        if(n>=g[i]){
            ans += solve(n-g[i],g,p,i+1,minp-p[i],dp);
            ans %= mod;
        }
        ans += solve(n,g,p,i+1,minp,dp);
        ans %= mod;
        return dp[i][n][max(0,minp)] = ans;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int dp[101][101][101];
        memset(dp, -1, sizeof(dp)); 
        return solve(n,group,profit,0,minProfit,dp);
    }
};