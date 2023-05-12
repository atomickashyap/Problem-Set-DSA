//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        unordered_set<int>s;
        for(int i=0;i<n;i++)
            s.insert(arr[i]);
        
        if(s.find(0)==s.end())
        return -1;
        if(s.size()==1)
        return 0;
        
        vector<int>v;
        int count=0;
        
        for(int i=1;i<n-1;i++)
        if(arr[i]==0 && arr[i+1]!=0)
        count++;
        else
        continue;
        
        return count+1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends