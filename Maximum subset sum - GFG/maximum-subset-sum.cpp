//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
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
    int func(int N, vector<int> &arr){
        int ptr1 = arr[0],ptr2 = 0,sum;
        for(int i=1;i<N;i++){
            sum = arr[i] + max(ptr1,ptr2);
            ptr2 = ptr1;
            ptr1 = sum;
        }
        if(N==1) return ptr1;

        return sum;

}

long long findMaxSubsetSum(int N, vector<int> &arr){
        vector<int>vec;
        for(int i=0; i<N-1; i++){
            vec.push_back(arr[i]);
        }
        return max(func(N-1, vec), func(N, arr));

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
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends