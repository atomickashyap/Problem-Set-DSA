class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int d) {
    int sum = 0;
    int n = nums.size();
    for(int i =0;i<n;i++)
    {
        sum+=nums[i];
    }
    if (d > sum || d < -sum) {
            return 0;
    }
    if((sum+d)%2 != 0)
        return 0;

    sum =(sum+d)/2;

    vector<vector<int>> t(n+1,vector<int>(sum+1,0));
    for (int i = 0; i < n+1; i++)
    {
        t[i][0] = 1;
    }

    for(int i =1;i<n+1;i++)
    {
        for(int j =0;j<sum+1;j++)
        {
            if(nums[i-1]<=j)
            {
                t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
    }
};