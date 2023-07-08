class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN,pref = 1,surf = 1;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++)
        {
            if(pref ==0) pref =1;
            if(surf ==0)surf = 1;
            surf *=nums[n-1-i];
            pref*=nums[i];
            maxi = max(maxi, max(pref,surf));
        }
            
            
            
        return maxi;
    }
};