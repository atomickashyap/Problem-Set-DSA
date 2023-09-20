//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        long long n = dividend, m = divisor;
        long long sign = (n<0 ^ m<0) ? -1:1;
        n = abs(n);
        m = abs(m);
        long long t = 0;
        long long q = 0;
        
        for(long long i = 31;i>=0;i--)
        {
            if(t+(m<<i) <= n)
            {
                t+=(m<<i);
                q = q | (1<<i);
            }
        }
        
        if(sign == -1) q = -q;
        return q;
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends