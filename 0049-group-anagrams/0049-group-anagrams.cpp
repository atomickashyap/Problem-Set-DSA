class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        for(auto it:strs)
        {
            string st = it;
            sort(st.begin(),st.end());
            mp[st].push_back(it);
            // if(mp.find(st)!=end)
            // {
            //     mp[st].push_back(it);
            // }
            // else{
            //     mp[st].push_back
            // }
        }
        
        cout<<mp.size();
        for(auto it:mp)
        {
            vector<string>temp;
            // cout<<it.second[0]<<endl;
            for(int i =0;i<it.second.size();i++)
            {
                temp.push_back(it.second[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};