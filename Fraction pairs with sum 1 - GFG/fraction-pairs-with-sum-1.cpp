//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int countFractions(int n, int a[], int b[])
    {
        for(int i=0;i<n;i++)
        {
            int x=__gcd(a[i],b[i]);
            a[i]/=x;
            b[i]/=x;
        }
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[{b[i],a[i]}]++;
        }
        int ans=0;
        for(auto it:mp)
        {
            auto x=it.first;
            int cnt=it.second;
            if(x.first!=2)
            {
                ans+=(cnt*mp[{x.first,x.first-x.second}]);
                mp[x]=0;
                
            }
        }
        int y=mp[{2,1}];
        ans+=(y*(y-1))/2;
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends