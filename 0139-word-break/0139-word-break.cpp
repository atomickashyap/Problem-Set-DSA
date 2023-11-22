
class Solution {
private:
    unordered_set<string>st;
    std::vector<int> dp = std::vector<int>(301,-1);
// int dp[301];
private:
    bool solver(string s, int idx)
    {
        if(idx == s.length())
        {
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        if(st.find(s)!=st.end())
            return true;
        for(int l = 1; l<=s.length();l++)
        {
            string temp = s.substr(idx,l);
            if(st.find(temp)!=st.end() && solver(s,idx+l))
            {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        // memset(dp,-1,sizeof(dp));        
        for(int i =0;i<wordDict.size();i++)
        {
            st.insert(wordDict[i]);
        }
        
        return solver(s,0);
        
    }
};