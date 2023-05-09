//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod = 1000000007;

    void multiply(vector<vector<int>> &a, vector<vector<int>> &b) {

        vector<vector<int>> mul;
        mul.resize(3);
        for (int i = 0; i < 3; i++) {
            mul[i].resize(3);
            for (int j = 0; j < 3; j++) {
                mul[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    long long int temp =
                        ((long long int)a[i][k] * b[k][j]) % mod;
                    mul[i][j] += temp;
                    mul[i][j] %= mod;
                }
            }
        }
        a = mul;
    }

    int power(vector<vector<int>> &mat, long long int N) {
        vector<vector<int>> M = {{1, 1, 0}, {1, 0, 0}, {0, 1, 0}};

        if (N == 1) {
            return (mat[0][0] + mat[0][1]) % mod;
        }

        power(mat, N / 2);

        multiply(mat, mat);

        if (N % 2 != 0) {
            multiply(mat, M);
        }

        return (mat[0][0] + mat[0][1]) % mod;
    }

    int countStrings(long long int N) {

        vector<vector<int>> mat = {{1, 1, 0}, {1, 0, 0}, {0, 1, 0}};
        if (N == 2) return 3;
        if (N == 1) return 2;

        return power(mat, N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends