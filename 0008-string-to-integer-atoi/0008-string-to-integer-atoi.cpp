class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0)   return 0;
        int i =0;
        while(i<s.size() && s[i]==' ')
        {
            i++;
        }
        s = s.substr(i);
        
        int sign = +1;
        long long ans = 0;
        
        if(s[0] == '-') sign = -1;
        
        int maxi = INT_MAX,mini = INT_MIN;
        i = (s[0]=='-'||s[0]=='+')? 1:0;
        while(i<s.length())
        {
            if(s[i]==' ' || !isdigit(s[i]))  return sign*ans;
            
            ans = ans*10 + s[i]-'0';
            if(sign == -1 && -1*ans < mini) return mini;
            if(sign == 1 && ans > maxi) return maxi;
            i++;
        }   
        return int(sign*ans);
        
    }
};