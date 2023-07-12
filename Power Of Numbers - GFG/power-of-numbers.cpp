//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
    long long powerLL(long long x, long long n, long long mod) {
        long long result = 1;
        while (n) {
            if (n & 1) {
                result = result * x % mod;
            }
            x = x * x % mod;
            n = n / 2;
        }
        return result;
    }
    public:
    //You need to complete this fucntion
    
long long mod = 1e9+7;
    long long fun(int a,int n){
        if(n==0){
            return 1;
        }  
        long long p = fun(a,n/2);
        if(n&1){
            return ((p*p)%mod*a%mod)%mod;
        }else{
            return ((p*p))%mod;
        }
    }
    long long power(int N,int R)
    {
       //Your code here
       // power exponentiation
       return fun(N,R);
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends