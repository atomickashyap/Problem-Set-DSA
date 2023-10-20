//{ Driver Code Starts
#include <iostream>
using namespace std;
#define ll long long

ll findMaxProduct(int A[], int n, int k);

int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int k;
		cin>>k;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
	
		cout<<findMaxProduct(a,n,k)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends


/*You are required to complete the function*/
#include<bits/stdc++.h>
long long findMaxProduct(int arr[], int n, int k)
{
//Your code here
    int prod = 1, nzp = 1, ct = 0, ans = INT_MIN;

    for (int i = 0; i < k; i++)
    {
        prod *= arr[i];
        if (arr[i] == 0)
            ct++;
        else
            nzp *= arr[i];
    }
    ans = max(ans, prod);
    for (int j = k; j < n; j++)
    {
        if (arr[j] != 0)
        {
            if (arr[j - k] != 0)
            {
                nzp /= arr[j - k];
                nzp *= arr[j];
                if(ct == 0)
                    prod = nzp;

            }
            else {
                nzp *= arr[j];
                ct--;
                if (ct == 0)
                    prod = nzp;
            }
        }
        else {
            ct++;
            prod *= arr[j];
            if (arr[j - k] != 0)
            {
                nzp /= arr[j - k];
            }
            else {
                ct--;
            }
        }
        ans = max(ans,prod);
    }
    return ans;
}


