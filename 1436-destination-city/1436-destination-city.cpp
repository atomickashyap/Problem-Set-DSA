class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,bool> mp;
        for(auto it: paths)
        {
            mp.insert({it[1],false});    
        }
        for(auto it: paths)
        {
            if(mp.find(it[0])!= mp.end())
                mp[it[0]] = true;  
        }
        for(auto it:mp)
        {
            if(it.second == false)
                return it.first;
        }
        return "";
    }
};