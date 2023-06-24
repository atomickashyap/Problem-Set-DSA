//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        int ans =0;
        string check="";
        for(int i = 0;i<k;i++)
        {
            check+=str[i];
        }
        // cout<<check;
        for(int i = 0;i<n;i++)
        {
            string temp = arr[i];
            if(temp.length() >=k)
                {
                int incre = 0;
                for(int j = 0;j<k;j++)
                {
                    if(temp[j] == check[j])
                    {
                        incre++;
                    }
                }
                if(incre == k)
                {
                    ans++;
                }
            }
        }
        
        
        
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends