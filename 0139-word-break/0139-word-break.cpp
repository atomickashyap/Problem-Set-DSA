class Solution {
public:
    map<char,vector<string>> m;
    vector<int> dp;
    bool f(string s, int i){
        if(i==s.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        bool ans=false;
        for(auto it:m[s[i]]){
            if(s.substr(i,it.size())==it){
                ans|=f(s,i+it.size());
            }
        }
        return dp[i]=ans;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(),-1);
        for(auto it:wordDict){
            m[it[0]].push_back(it);
        }
        return f(s,0);
    }
};