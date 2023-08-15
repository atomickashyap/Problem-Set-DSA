//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int cnt_one = 0;
        int max_sum = 0;
        int curr_sum=0;
        for(int i =0;i<n;i++)
        {
            if(a[i]==1)
            {
                cnt_one++;
                a[i] = -1;
            }
            else
                a[i] = 1;
        }
        for(int i= 0;i<n;i++)
        {
            curr_sum+=a[i];
            max_sum = max(max_sum,curr_sum);
            if(curr_sum<0)
                curr_sum = 0;
            
        }
        return max_sum+cnt_one;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends