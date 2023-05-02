class Solution {
public:
    int maxArea(vector<int>& height) {

        // Two pointer Approach
        int n = height.size();

        int start = 0;
        int end = n-1;

        int maxArea = 0;

        while(start<end){
            // Find the current area

            // Area = length*bread
            int currentArea = min(height[start],height[end])*(end-start);

            if(currentArea > maxArea){
                maxArea = currentArea;
            }

            // Now move the pointers 

            if(height[start]<height[end]){
                // move the start

                start++;
            }
            else
            {
                // move the end

                end--;
            }
        }

        return maxArea;
    }
};