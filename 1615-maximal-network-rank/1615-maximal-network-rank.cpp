class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<int>adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ans=0;
                ans+=adj[i].size();
                ans+=adj[j].size();
                if(adj[j].find(i)!=adj[j].end())
                {
                    ans--;
                }
                maxi=max(maxi,ans);
            }
        }
        return maxi;
    }
};