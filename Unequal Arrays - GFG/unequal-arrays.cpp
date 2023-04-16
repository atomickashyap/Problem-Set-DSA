//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end(),greater<int>());
        
        long long numMoves=0,sumDiffs=0;
        vector<int>odd,even;
        for(int i=0;i<N;i++){
            if(B[i]%2==0)
            even.push_back(B[i]);
            
            else
            odd.push_back(B[i]);
        }
        for(int i=0;i<N;i++){
            if(A[i]%2==0){
                if(even.size()==0) return -1;
                
                sumDiffs+=even.back()-A[i];
                numMoves+=abs(even.back()-A[i])/2;
                even.pop_back();
            }
            else{
                if(odd.size()==0) return -1;
                
                sumDiffs+=odd.back()-A[i];
                numMoves+=abs(odd.back()-A[i])/2;
                odd.pop_back();
            }
        }
        if(sumDiffs!=0) return -1;
        return numMoves/2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends