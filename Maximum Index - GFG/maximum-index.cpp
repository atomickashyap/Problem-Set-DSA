//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
          vector<int> leftMin(n),rightMax(n);

        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(arr[i], leftMin[i-1]);
        }

        rightMax[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(arr[i], rightMax[i+1]);
        }

        int i = 0, j = 0;
        int result = -1;
        while (i < n && j < n) {
            if (leftMin[i] <= rightMax[j]) {
                result = max(result, j - i);
                j++;
            } else {
                i++;
            }
        }

        return result;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends