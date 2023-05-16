//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool checkpower(string &str)
    {
        long double num=0;
        
        //converting binary string to decimal num
        
        for(int i=0; i<str.size();i++)
        {
            num = num*2 + (str[i]-'0');
        }
        
        if(num==0) return false; //0 is not any power of 5 so false
        
        double logval = log2(num)/log2(5); //to check power with base 5
        
        if(logval==round(logval)) return true; //to find if logval is integer
        
        return false;
    }
    
    int solve(int index, string &s)
    {
        if(index>=s.size()) return 0;
        
        int mini=INT_MAX;
        
        for(int i=0;index+i<s.size();i++)
        {
            string curr = s.substr(index,i+1);
            
            if(checkpower(curr))
            {
                if((index+i!=s.size()-1 && s[index+i+1]=='1') || index+i==s.size()-1)
                {
                    int cutans = solve(index+i+1,s);
                    
                    if(cutans!=INT_MAX) cutans++;
                    
                    mini = min(cutans,mini);
                }
            }
        }
        
        return mini;
    }
    
    int cuts(string s)
    {
        if(s[0]=='0') return -1; //for leading 0s
        
        int ans = solve(0,s);
        
        if(ans==INT_MAX) return -1;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends