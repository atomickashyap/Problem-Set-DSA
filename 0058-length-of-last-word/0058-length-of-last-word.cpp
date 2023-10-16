class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int cnt = 0;
        for(int i = len-1;i>=0;i--)
        {
            if(s[i]!=' ')
                cnt++;
            else if(cnt!=0 && s[i]==' ')
            {
                return cnt;
            }
            
        }
        return cnt;
    }
};