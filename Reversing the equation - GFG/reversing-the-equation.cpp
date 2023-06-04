//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans = "";
            stack<char> st;
            for (int i = 0; i < s.length(); i++)
            {
                st.push(s[i]);
            }
        
            string num = "";
            string sym = "";
            while (!st.empty())
            {
        
                if (st.top() >= '0' && st.top() <= '9')
                {
                    num.push_back(st.top());
                    st.pop();
                }
                else {
        
                    sym.push_back(st.top());
                    st.pop();
                    reverse(num.begin(), num.end());
                    ans.append(num);
                    ans.append(sym);
                    num = ""; sym = "";
                }
            }
            reverse(num.begin(), num.end());
            ans.append(num);
        
            return ans;

        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends