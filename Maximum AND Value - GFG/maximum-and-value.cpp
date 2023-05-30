//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    private:
    int function( int pattern, int *arr, int size)
    {
        int cnt = 0;
        for(int i=0;i<size;i++)
        {
            if(pattern == (pattern&arr[i]))
            {
                cnt++;
            }
        }
        return cnt;
    }
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        // Your code here
        int pattern;//making pattern
        int res = 0; // hold our ans;
        int counter;// counter the number of value which with equal to our pattern
        
        for(int bits = 16;bits>=0;bits--)
        {
            pattern = res | (1<<bits);
            counter = function(pattern, arr, N);
            if(counter >1)
            {
                res = pattern;
            }
        }
        
        
        return res;
        
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends