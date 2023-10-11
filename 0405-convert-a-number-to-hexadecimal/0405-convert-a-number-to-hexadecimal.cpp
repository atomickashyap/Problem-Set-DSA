class Solution {
public:
    string toHex(int n) {
        if(n==0)
            return to_string(0);
        unsigned int num = n;
        string digits = "0123456789abcdef";
        string res = "";
        while(num>0)
        {
            int temp = num%16;
            res+=digits[temp];
            num=num/16;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};