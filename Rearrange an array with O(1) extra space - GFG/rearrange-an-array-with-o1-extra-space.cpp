//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    
   void arrange(long long arr[], int n) 
    {
        int arr1[n];
        for(int i=0;i<n;i++)
        {
            arr1[i] = arr[i];
        }
        
        for(int i=0;i<n;i++)
        {
            arr[i] = (arr1[arr1[i]]);
        }
        //for(int i=0;i<n;i++) arr[i] /= n;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends