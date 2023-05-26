//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    private:
    int check(int pattern, int arr[],int size)
    {
        int counter = 0;
        for (int i = 0; i < size; i++)
        {
            if (pattern == (pattern & arr[i]))
                counter++;
        }
        return counter;
    }
    int function(int arr[],int size)
    {
        int res = 0, counter;
        for (int bits = 16; bits >= 0; bits--)
        {
            counter = check( res | (1 << bits) , arr, size);
            if (counter >= 2)
            {
                res = res | (1 << bits);
            }
        }
        return res;
    }
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        // Your code here
        return function(arr,N);
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