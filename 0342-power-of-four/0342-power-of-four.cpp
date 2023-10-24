class Solution {
public:
    bool isPowerOfFour(int n) {
        
        // edge case
        
        if(n <= 0)
            return false;
        
        // this condition must be satisfied, if any number is power of 4
        
        if((n & (n - 1)) == 0 && (n - 1) % 3 == 0)
            return true;
        
        return false;
    }
};