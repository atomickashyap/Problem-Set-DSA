class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0)
            return ans;
        int flag = 1;
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];
        for(auto it:intervals)
        {
            if(it[0]<=temp[1])
            {
                temp[1] = max(it[1],temp[1]);
                flag = 1;
            }
            else
            {
                ans.push_back(temp);
                temp = it;
                flag = 0;
                // cout<<it[1] <<" "<<temp[1]<<endl;
            }
            // cout<<flag<<"as\n";
        }
        
        // if(flag ==1)
            ans.push_back(temp);
        
        
        return ans;
    }
};