class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr.size()<=2)
        {
            return true;
        }
        int common_difference = abs(arr[1] - arr[0]);
        for(int i = 1;i<arr.size()-1;i++)
        {
            if(common_difference != abs(arr[i]-arr[i+1]))
                return false;
        }
        return true;
    }
};