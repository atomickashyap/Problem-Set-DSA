//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int> kthSmallestNum(int n, vector<vector<int>> &arr, int q, vector<int> queries)
{
    sort(arr.begin(), arr.end());
    int index = 0;
    // Merge ranges
    for (int i = 1; i < n; i++)
    {
        if (arr[index][1] >= arr[i][0])
        {
            arr[index][1] = max(arr[index][1], arr[i][1]);
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }
    vector<int> temp;
    int co = 0;
    for (int j = 0; j <= index; j++)
    {
        co += (arr[j][1] - arr[j][0] + 1);
        temp.push_back(co);
    }

    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int x = queries[i];
        auto it = lower_bound(temp.begin(), temp.end(), x) - temp.begin();

        if (it > index)
        {
            ans.push_back(-1);
            continue;
        }
        if (it != 0)
        {
            if (it - 1 <= index && temp[it - 1] < x)
            {
                x -= temp[it - 1];
            }
        }

        while (it <= index && temp[it] < x)
        {
            x -= temp[it];
            it++;
        }
        if (it > index)
        {
            ans.push_back(-1);
            continue;
        }

        ans.push_back(arr[it][0] + x - 1);
    }
    return ans;
}
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends