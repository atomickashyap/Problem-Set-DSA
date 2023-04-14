class Solution {
public:
  int kthElement(int ar1[], int ar2[], int n, int m, int k)
  {
    int gap = ceil((float)(n + m) / 2);
    while (gap > 0) {
      int i = 0;
      int j = gap;
      while (j < (n + m)) {
        if (j < n && ar1[i] > ar1[j]) {
          swap(ar1[i], ar1[j]);
        } else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
          swap(ar1[i], ar2[j - n]);
        } else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
          swap(ar2[i - n], ar2[j - n]);
        }
        j++;
        i++;
      }
      if (gap == 1) {
        gap = 0;
      } else {
        gap = ceil((float) gap / 2);
      }
    }
    if (k <= n)
    {
      return ar1[k - 1];
    }
    return ar2[k - n - 1];
  }
};

//{ Driver Code Starts.

// Driver code
int main()
{
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
      cin >> arr1[i];
    for (int i = 0; i < m; i++)
      cin >> arr2[i];

    Solution ob;
    cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
  }
  return 0;
}
// } Driver Code Ends