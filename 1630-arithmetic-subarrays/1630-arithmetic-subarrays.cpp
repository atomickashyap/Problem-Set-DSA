class Solution {
public:
    // Function to check if an array is an arithmetic progression
    bool check(vector<int>& arr) {
        
        int maxEl = INT_MIN; // Initialize maximum element
        int minEl = INT_MAX; // Initialize minimum element
        int n = arr.size();

        unordered_set<int> s; // Using set for constant time look-up
        for(auto el : arr){
            // Finding minimum and maximum elements
            minEl = min(minEl, el);
            maxEl = max(maxEl, el);
            s.insert(el); // Inserting elements in the set
        }

        // Checking if the difference is consistent
        if( (maxEl - minEl)%(n-1) != 0) return false;
        int d = (maxEl - minEl) / (n-1); // Difference between elements
        int cur = minEl + d; // Starting from second element

        while(cur < maxEl){
            // Checking each element in the set
            if(s.find(cur) == s.end()) return false;
            cur += d;
        }

        return true; // Returns true if it's an arithmetic progression
    }
    
    // Function to check multiple subarrays
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            // Checking each subarray
            ans.push_back(check(arr));
        }
        
        return ans; // Returns a vector of boolean answers
    }
};