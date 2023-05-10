//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int> maxi,mini(N,0);
        int mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<N;i++){
            mx=max(mx,A[i]);
            maxi.push_back(mx);
        }
        for(int i=N-1;i>=0;i--){
            mn=min(mn,A[i]);
            mini[i]=mn;
        }
        int ans=0;
        for(int i=0;i<N-1;i++){
            
            if(maxi[i]+mini[i+1]>=K){
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends