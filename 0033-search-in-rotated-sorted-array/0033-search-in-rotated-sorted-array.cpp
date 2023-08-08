class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0, j=n-1;
        while(i<=j)
        {
            //For rotated arrays (Case 1), 
            if(nums[i]>=nums[j])
            {
                //check if the target matches at ith or jth
                if(target==nums[i])
                return i;
                else if(target==nums[j])
                return j;
                //if not, iteratively increment i and decrement j.
                else
                i++;
                j--;
            }
            else
            {
                //nums[i]<nums[j], array is sorted between ith and jth index
                //apply binary search
                int mid = i + (j - i) / 2;
                if(nums[mid]<target)
                    i=mid+1;
                else if(nums[mid]>target)
                    j=mid-1;
                else
                return mid;
            }
        }
        //if Element is not found return -1.
        return -1;
    }
};