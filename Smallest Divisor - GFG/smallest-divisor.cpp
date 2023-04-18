//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
   private:
    bool isValid(vector<int>& nums, int K, int divisor){
        int sum = 0;
        for(auto num: nums){
            sum += num/divisor;
            if(num % divisor  !=  0)
                sum++;
        }
        
        return sum <= K;
    }
  public:
    int smallestDivisor(vector<int>& nums, int K) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        
        while(start <= end){
            int mid = start+(end-start)/2;
            if(isValid(nums, K, mid))
                end = mid-1;
            else
                start = mid+1;
        }
        
        return start;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends