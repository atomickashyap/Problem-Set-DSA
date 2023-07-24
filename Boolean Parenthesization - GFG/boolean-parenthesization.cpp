//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for
int t[205][205][2];
class Solution{
private:
    int solve(string s,int i ,int j,bool check)
    {
        if(i>j) return false;
        if(i==j)
        {
            if(check == true)
            {
                return (s[i]=='T');
            }
            else
                return (s[i] == 'F');
        }
        string temp = to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(check));
    
        if(t[i][j][check] != -1)
        return t[i][j][check] ;
        
        int ans = 0;
        for(int k = i+1;k<=j-1;k=k+2)
        {
            int lT = solve(s,i,k-1, true);
            int rF = solve(s,k+1,j,false);
            int lF = solve(s,i,k-1,false);
            int rT = solve(s,k+1,j,true);
            
            if(s[k] =='&')
            {
                if(check ==  true)
                {
                    ans+= lT *rT;
                }
                else{
                    ans+=(lT*rF)+(lF*rT) + (lF * rF);
                }
            }
            else if(s[k] == '|')
            {
                if(check == true)
                    ans+=(rT*lT)+(rT*lF)+(lT*rF);
                else
                    ans+=(rF*lF);
            }
            else if(s[k] == '^')
            {
                if(check == true)
                    ans+=(lT*rF)+(lF*rT);
                else
                    ans+=(rF*lF) + (rT*lT);
            }
        }
        return t[i][j][check]=ans%1003;;
    }
public:
    int countWays(int N, string S){
        // code here
        memset(t,-1,sizeof(t));
        return solve(S,0,N-1,true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends