class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256,-1);
        int ans = 0;
        int left = 0,right = 0;
        while(right<s.length())
        {
            if(mpp[s[right]]!=-1) left = max(left,mpp[s[right]]+1);
            mpp[s[right]] = right;
            
            ans = max(ans, right-left+1);
            right++;
        }
            
        
        
        
        return ans;
    }
};