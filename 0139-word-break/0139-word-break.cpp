class Solution {
    unordered_set<string> st;
    std::vector<int> dp = std::vector<int>(301,-1);
private:
    bool solve(string s,int idx)
    {
        if(s.length() == idx)
        {
            return true;
        }
        if(dp[idx] !=-1)
            return dp[idx];
        if(st.find(s) !=st.end())
        {
            return dp[idx] = true;
        }
        
        for(int l = 1;l<s.length();l++)
        {
            string temp = s.substr(idx,l);
            if((st.find(temp)!=st.end()) && solve(s,idx+l))
            {
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i =0;i<wordDict.size();i++)
        {
            st.insert(wordDict[i]);
        }
        return solve(s,0);
    }
};