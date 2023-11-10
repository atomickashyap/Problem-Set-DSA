class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i =0;
        while(i<n && s[i] == ' ')
        {
            i++;
        }
        if(n==0)
        {
            return 0;
        }
        s = s.substr(i);
        // cout<<s;
        int sign = 1;
        i = 0;
        if(s[i] == '-')
        {
            sign=-1;
        }
        if(s[i] == '-' || s[i] == '+')
        {
            i = 1;
        }
        long long ans =  0;
        int mini = INT_MIN,maxi = INT_MAX;
        while(i < s.length())
        {
            if(s[i] == ' ' || !isdigit(s[i]))   return sign*ans;
            ans = ans*10 + (s[i]-'0');
            if(ans*sign < mini) return mini;
            if(ans*sign > maxi) return maxi;
            i++;
        }
        
        return int(ans*sign);
    }
};