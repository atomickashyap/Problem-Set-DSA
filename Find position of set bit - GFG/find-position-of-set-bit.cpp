//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        if(N == 0)
            return -1;
        int cnt = 0;
        int set = 0;
        for(int i =0 ;i<32;i++)
        {
            int temp = 1<<i;
            
            if((N&temp) >0)
            {
                cnt++;
                set = i;
            }
        }
        if(cnt>1)   return -1;
        return set+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends