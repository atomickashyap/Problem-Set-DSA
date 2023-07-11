class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
             sum+=arr[i];
        }
        
        if((sum+target)%2 != 0) return 0;
        if (target > sum || target < -sum) {
            return 0;
        }
        
        sum = (sum+target)/2;
        
        int t[n+1][sum+1];
        
        for(int i = 0;i<n+1;i++)
        {
            for(int j =0;j<sum+1;j++)
            {
                if(i==0)
                    t[i][j] = 0;
                if(j==0)
                    t[i][j] = 1;
            }
        }
        
        for(int i = 1;i<n+1;i++)
        {
            for(int j =0;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                    t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
            
        return t[n][sum];
    }
};