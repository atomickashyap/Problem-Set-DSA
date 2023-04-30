//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &in,int k){
        // Code here
         int maxi=0;

        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,in[i][1]);
        }

        vector<int>v(maxi+2,0);

        for(int i=0;i<n;i++){

            v[in[i][0]]++;

            v[in[i][1]+1]--;

        }

        int ans=-1;

        for(int i=1;i<v.size();i++){

            v[i]+=v[i-1];
            if(v[i]>=k)
            {
                ans=i;
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
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends