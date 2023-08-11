//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long n;
    long long t[1001][1001];
    long long solve(int idx,int sum,int coins[]){
        if(sum==0){
            return 1;
        }
        if(idx==n){
            return 0;
        }
        if(t[idx][sum]!=-1){
            return t[idx][sum];
        }
        if(sum<coins[idx]){
            return t[idx][sum]=solve(idx+1,sum,coins);
        }
        
        long long take=solve(idx,sum-coins[idx],coins);
        long long skip=solve(idx+1,sum,coins);
        
        return t[idx][sum] =take+skip;
        
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        n=N;
        memset(t,-1,sizeof(t));
        return solve(0,sum,coins);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends