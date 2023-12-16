class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length())
            return false;
        unordered_map<char,int> smp;
        unordered_map<char,int> tmp;
        for(int i = 0;i<s.length();i++)
        {
            if(smp.find(s[i])==smp.end())
            {
                smp[s[i]] = 1;
            }
            else{
                smp[s[i]]++;
            }
        }
        for(int i = 0;i<t.length();i++)
        {
            if(tmp.find(t[i])==tmp.end())
            {
                tmp[t[i]] = 1;
            }
            else{
                tmp[t[i]]++;
            }
        }
        for(auto it:smp)
        {
            char temp = it.first;
            if(tmp[temp] != smp[temp])
                return false;
        }
        
        
        return true;
    }
};