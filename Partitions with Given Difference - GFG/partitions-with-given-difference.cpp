//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        long long mod = 1e9+7;
    int sum = 0;
    for(auto it : arr) sum+=it;
    
    if((sum+d)%2!=0) return 0;
    sum = (sum+d)/2;

    // int t[n+1][sum+1];
    vector<vector<int>> t(n+1,vector<int>(sum+1,0));
    // cout<<"sum = "<<sum<<"\n";
    
    // for(int i = 0;i<n+1;i++)
    //     {
    //         for(int j = 0;j<sum+1;j++)
    //         {
    //             if(i==0)
    //                 t[i][j] = 0;
    //             if(j == 0)
    //                 t[i][j] = 1;
    //         }
    //     }
        t[0][0] = 1;

    for(int i = 1;i<n+1;i++)
    {
        for(int j = 0;j<sum+1;j++)
        {
            if(arr[i-1] <=j)
            {
                t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j])%mod;
            }
            else
                t[i][j] = t[i-1][j]%mod;
        }
    }
    


    return t[n][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends