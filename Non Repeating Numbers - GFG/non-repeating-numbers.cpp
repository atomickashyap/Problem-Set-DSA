//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> arr) 
    {
        // Code here.
        int xorr = 0;
        for(int i=0;i<arr.size();i++)
        {
            xorr^=arr[i];
        }
        int setBit = 0;
        for(int i = 0;i<32;i++)
        {
            int curr = 1<<i;
            if((xorr&curr)!=0)
            {
                setBit = curr;
                break;
            }
        }
        int first = 0;
        int second = 0;
    
        for(int i = 0;i<arr.size();i++)
        {
            if((arr[i]&setBit)!=0)
            {
                
                first^=arr[i];
            }
                
            else
                second^=arr[i];
        }
    
        if(first>second)
            return {second,first};
    
        return {first,second};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends