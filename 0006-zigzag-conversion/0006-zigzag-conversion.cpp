class Solution {
public:
    string convert(string s, int numRows) {
         string ans;

        if(numRows==1) return s;

        int n = s.size();

        for(int i=0;i<numRows;i++) {
            
            int idx = i;
            while(idx < n) {
                ans += s[idx];

                idx += 2 * (numRows-1) - 2 * ((idx % (numRows-1)));
            }
        }
        return ans;
        
    }
};