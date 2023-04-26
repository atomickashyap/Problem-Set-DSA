class Solution {
public:
    int sum(int n)
    {
        int siu=0, ans;
        while(n)
        {
            siu+=n%10;
            n/=10;
        }
        if(siu>9)
            ans=sum(siu);
        
        else
            ans=siu;
        
        return ans;
    }
    
    int addDigits(int num) {
        return sum(num);
    }
};