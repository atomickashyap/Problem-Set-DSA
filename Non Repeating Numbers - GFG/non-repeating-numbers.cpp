//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n = nums.size();
        int xorr = 0;
        for(int i =0;i<n;i++)
        {
            xorr ^=nums[i];
        }
        // cout<<xorr<<" =";
        int setbit =0;
        for(int i = 0;i<=32;i++)
        {
            int num =  1<<i;
            if((xorr & num))
            {
                setbit = num;
                break;
            }
        }
        // cout<<setbit<<" = ";
        int first = 0,second = 0;
        for(int i = 0;i<n;i++)
        {
            if((nums[i] & setbit))
            {
                first^=nums[i];
            }
            else{
                second^=nums[i];
            }
        }
        
        
        if(first < second)
            return{first,second};
        
        return {second,first};
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