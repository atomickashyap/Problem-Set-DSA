//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        map<int,int> mp;
        for(int i = 0;i<n;i++)
        {
            if(mp.find(arr[i]) != mp.end())
            {
                mp[arr[i]]++;
            }
            else{
                mp[arr[i]] = 1;
            }
        }
        int ans = INT_MIN;
        int freq = INT_MAX;
        for(auto &it : mp)
        {
            if(ans < it.first && freq >=it.second)
            {
                ans = it.first;
                freq = it.second;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends