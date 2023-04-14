//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int lo = 0, hi = n-1;
        if(arr[0] < arr[1]) return arr[0];
        if(arr[n-1] > arr[n-2]) return arr[n-1];
        
        while(lo <= hi){
            int mid = (lo+hi)/2;
                // cout<<arr[mid]<<endl;
            if(arr[mid] < arr[mid+1] && arr[mid]>arr[mid-1]){
                return arr[mid];
            } 
            if(arr[mid] == arr[mid-1]){
                if(mid%2!=0)
                    lo = mid+1;
                else
                    hi = mid-1;
            }else if(arr[mid] == arr[mid+1]){
                if(mid%2!=0)
                    hi = mid-1;
                else
                    lo = mid+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends