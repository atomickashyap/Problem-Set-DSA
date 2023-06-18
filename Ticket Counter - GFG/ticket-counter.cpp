//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    int distributeTicket(int N,int K)
    {
        int start = 0 ,end =N;
        
        while(start<end){
            
            start = start+K;
            if(start>=end) return end;
            
            end = end - K;
            
            if(start >=end) return start+1;
        }
        return start;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends