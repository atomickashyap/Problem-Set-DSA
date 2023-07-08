class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        int prev2= 0,prev = 1;
        
        for(int i =2;i<n+1;i++)
        {
            int curr = prev2+prev;
            prev2 = prev;
            prev =curr;
        }
        
        return prev;
    }
};