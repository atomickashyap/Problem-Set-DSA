class Solution {
public:
    double power(double x ,long n){
        if(n==0) return 1;
        
        if(!(n&1)) return power(x*x,n/2); // even power
        return x*power(x,n-1); // odd power 
    }
    
    double myPow(double x, int n) {
        if(n==0) return 1;
        
        long l=abs((long)n);
        double ans=power(x,l);
        
        return (n>0 ? ans:1/ans);
    }
};