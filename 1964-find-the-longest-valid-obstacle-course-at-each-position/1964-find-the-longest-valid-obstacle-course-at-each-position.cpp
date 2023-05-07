class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> vals, ans; 
        for (auto& x : obstacles) {
            auto it = upper_bound(vals.begin(), vals.end(), x); 
            ans.push_back(it-vals.begin()+1); 
            if (it == vals.end()) vals.push_back(x); 
            else *it = x; 
        }
        return ans; 
    }
};