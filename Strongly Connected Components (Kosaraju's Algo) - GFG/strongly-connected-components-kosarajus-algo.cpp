//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
    void dfs(vector<int> adj[],vector<int>&vis, stack<int> &stc ,int src)
    {
        vis[src] = 1; //visted
        for(auto child: adj[src])
        {
            if(vis[child]) continue;
            dfs(adj,vis,stc,child);
        }
        stc.push(src);
    }
    
    void dfs_scc(vector<int> adj[], vector<int> &vis, int src)
    {
        vis[src] = 1;
        for(auto child : adj[src])
        {
            if(vis[child]) continue;
            dfs_scc(adj, vis,child);
        }
    }
    
    
     public:
     //Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<vector<int>>& nums)
    {
        //code here
        vector<int> adj[v];
        vector<int> adjT[v]; //transpose of the adj list
        
        for(int i =0 ;i<nums.size();i++)
        {
            for(int j = 0;j<nums[i].size();j++)
            {
                // cout<<nums[i][j]<<" ";
                adj[i].push_back(nums[i][j]); 
            }
            // cout<<endl;
        }
        
        stack<int> stc; // to store the element acc to finishing time 
        vector<int> vis(v,0); // 0 for not visited and 1 for vistited
        
        for(int i = 0;i<v;i++)
        {
            if(!vis[i])
                dfs(adj,vis,stc ,i);
        }
        for(int i =0;i<v;i++)
        {
            vis[i] = 0;
        }
        for(int i =0 ;i<nums.size();i++)
        {
            for(int j = 0;j<nums[i].size();j++)
            {
                adjT[nums[i][j]].push_back(i); 
            }
        }
        int scc = 0;
        while(!stc.empty())
        {
            int node = stc.top();
            stc.pop();
            if(!vis[node])
            {
                scc++;
                dfs_scc(adjT,vis,node);
            }
        }
        return scc;
        
    
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends