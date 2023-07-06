class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int mn = INT_MAX;
        
        long long int sum = 0;
        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum>=target)
            {
                sum=sum - nums[i];
                mn = min(mn,j-i+1);
                i++;
            }
            j++;
        }
        
        if(mn == INT_MAX) return 0;
        return mn;
    }
};