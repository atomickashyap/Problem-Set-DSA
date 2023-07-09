//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here
            
            int sum = 0, maxi;
            bool check = true;
            string ans,ref;
            char start= w[0];
            for(int i = 0;i<n;i++)
            {
                if(x[i]==start)
                {
                    maxi = b[i];
                    ans+=start;
                    check = false;
                    break;
                }
            }
            if(check)
            {
                maxi = start;
                ans+=start;
            }
            
            
            for(int i = 0;i<w.length();i++)
            {
                check = true;
                char k = w[i];
                ref+=k;
                for(int j =0;j<n;j++)
                {
                    if(x[j]==k)
                    {
                        sum+=b[j];
                        check = false;
                        break;
                    }
                }
                
                if(check)
                    sum+=k;
                    
                if(maxi < sum)
                {
                    maxi = sum;
                    ans =ref;
                }

                if(sum <0)
                {
                    sum=0;
                    ref ="";
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends