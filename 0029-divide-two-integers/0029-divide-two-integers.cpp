class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648 && divisor == -1) return 2147483647;
        
        if(dividend == -2147483648 && divisor == 1) {
            return -2147483648;
        }
        long long n = dividend, m = divisor;
        long long sign  = (n<0 ^ m<0)? -1:1;
        
        n = abs(n);
        m = abs(m);
        // dividend - quotient*divisor >=0;
        long long q = 0;
        long long t = 0;
        
        for(int i =31;i>=0;i--)
        {
            if(t+(m<<i)<=n)
            {
                t+=(m<<i);
                q+=(1LL<<i);
            }
        }
        
        
        
        return int(q*sign);
    }
};