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
            string ans,ref;
            map<char,int> mp;
            for(int i = 0;i<n;i++)
            {
                char temp =x[i];
                mp[temp] = b[i];
            }
            char start= w[0];
            if(mp.find(start)!=mp.end())
            {
                maxi = mp[start];
                ans+=start;
            }
            else{
                maxi = start;
                ans+=start;
            }
            
            for(int i = 0;i<w.length();i++)
            {
                char k = w[i];
                ref+=k;
                if(mp.find(k)!= mp.end())
                {
                    sum+=mp[k];
                }
                if(mp.find(k)==mp.end())
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