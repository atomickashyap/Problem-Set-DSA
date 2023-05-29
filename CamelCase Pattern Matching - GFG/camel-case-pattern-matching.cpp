//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<pair<int, string>>ans;
        
        for(int i=0; i<N; i++)
        {
            int m=Dictionary[i].length();
            string s="";
            for(int j=0; j<m; j++)
            {
                if(Dictionary[i][j]>='A' && Dictionary[i][j]<='Z')
                    s+=Dictionary[i][j];
            }
            ans.push_back(make_pair(i,s));
        }
        
        vector<string>final;
        int n=Pattern.size();
        
        for(int i=0; i<N; i++)
        {
            if(Pattern==ans[i].second.substr(0,n))
                final.push_back(Dictionary[ans[i].first]);
            //cout<<ans[i].second<<endl;
                
        }
        if(final.size()==0)
          final.push_back("-1");
        return final;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends