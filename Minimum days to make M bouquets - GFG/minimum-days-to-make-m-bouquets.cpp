//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int m, int k, vector<int> &arr){
      // Code here
      int n=arr.size(),low=1,high=1e9,minDays=-1 ; 
        if(n<m*k) return -1 ; 
        while(low<=high){
            int mid = (low+high)>>1 ; 
            int flowers=0,bouqs=0 ; 
            for(int i=0 ; i<n ; i++){
                if(arr[i]>mid){
                    flowers=0 ; 
                }
                else if(++flowers==k){
                    bouqs++ ; 
                    flowers=0 ; 
                }
            }
            if(bouqs<m){
                low=mid+1 ; 
            }
            else{
                minDays=mid ; 
                high=mid-1 ; 
            }
        }
        return minDays ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends