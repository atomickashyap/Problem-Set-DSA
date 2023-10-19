class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string> rowAns(numRows);
        if(numRows == 1)
            return s;
        
        bool flag = false;
        int i = 0;
        for(auto ch:s)
        {
            rowAns[i]+=ch;
            if(i ==0 || i == (numRows-1))
            {
                flag = !flag;
            }
            if(flag == true)
                i++;
            else
                i--;
        }
        string ans;
        for(auto it: rowAns)
        {
            ans+=it;
        }
        
        
        
        return ans;
    }
};