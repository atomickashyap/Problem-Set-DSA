class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0,j=0,ans = 0;
        map<char,int>mp;
        while(j<n)
        {
            mp[s[j]]++;
            if(mp.size() > (j-i+1))
            {
                j++;
            }
            if(mp.size() == (j-i+1))
            {
                ans = max(ans,(j-i+1));
                j++;
            }
            else if(mp.size() < (j-i+1))
            {
                while(mp.size()<(j-i+1))
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};