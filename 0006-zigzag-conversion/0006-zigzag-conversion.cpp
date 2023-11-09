class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> vec(numRows);
        bool flag = false;
        int i = 0;
        for(auto ch:s)
        {
            vec[i]+=ch;
            if(i == 0 || i == numRows-1)
                flag = !flag;
            if(flag==true)
                i++;
            if(flag==false)
                i--;
        }
        string ans;
        for(auto it:vec)
            ans+=it;
        return ans;
    }
};