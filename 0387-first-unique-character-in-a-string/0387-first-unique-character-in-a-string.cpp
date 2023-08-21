class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int ,int>>t(26,{0,-1});
        for(int i = 0;i<s.length();i++)
        {
            char ch = s[i];
            int val = t[s[i] - 'a'].first;
            val++;
            t[s[i]-'a'] = {val,i};
            
        }
        for(int i = 0;i<s.length();i++)
        {
            int val = t[s[i] - 'a'].first;
            if(val == 1)
                return t[s[i] - 'a'].second;
        }
        return -1;
    }
};