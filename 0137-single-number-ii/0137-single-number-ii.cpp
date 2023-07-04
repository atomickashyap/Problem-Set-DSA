class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(auto it :nums)
        {
            if(m.find(it)==m.end())
            {
                m.insert({it,1});
            }
            else
                m[it]++;
        }
        
        for(auto it: m)
        {
            if(it.second == 1)
                return it.first;
        }
        
        return 0;
    }
};