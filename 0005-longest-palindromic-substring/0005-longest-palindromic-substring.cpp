class Solution {
private:
    
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        string ans;
        int maxlength = 0;
        for(int diff = 0;diff<n;diff++)
        {
            for(int i = 0,j = i+diff;j<n;i++,j++)
            {
                if(i == j)
                    dp[i][j]= 1;
                else if(diff ==1)
                {
                    if(s[i] == s[j])
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 0;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1])
                        dp[i][j] = 2+dp[i+1][j-1];
                }
                if(dp[i][j])
                {
                    if(j-i+1>maxlength)
                    {
                        maxlength = j-i+1;
                        ans = s.substr(i,maxlength);
                    }
                }
            }
        }
        
        return ans;
    }
};