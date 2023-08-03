class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if(dividend == -2147483648 && divisor == -1) return 2147483647;
        
        if(dividend == -2147483648 && divisor == 1) {
            return -2147483648;
        }
        int sign = ((dividend<0) ^ (divisor<0))? -1:1;//basically if any one is true(negative)
        //then the sign value will be negative other wise it will be positive;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        // logic is basically how to represent a number in term of quotient and remainder
        // Number = Divisor X  (Quotient) + Remainder;
        // 10    =  3 X(3) + 1;
        
        long long quotient = 0, temp = 0;
        
        for(int i = 31;i>=0;i--)
        {
            
            if((temp+(divisor<<i)) <= dividend)
            {
                temp+=divisor<<i;
                quotient += 1LL <<i;
            }
            
        }
        
        
        if(sign == -1)
            quotient = -quotient;
        
        return quotient;
        
    }
};