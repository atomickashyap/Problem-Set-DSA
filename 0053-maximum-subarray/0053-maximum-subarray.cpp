class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN,temp =0;
        for(int i=0;i<nums.size();i++)
        {
            temp+=nums[i];
            maxi = max(temp,maxi);
            if(temp <0)
                temp =0;
        }
        return maxi;
    }
};