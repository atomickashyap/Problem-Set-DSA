//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(std::vector<int> adjL[], int vertex, vector<bool> &vis,vector<int> &ans) //Parameter part for downward
    {
      // Take action on vertex after entering the vertex
      vis[vertex] = true;
      ans.push_back(vertex);
      for (auto child : adjL[vertex])
      {
        if (vis[child]) continue;
        //Take action on child before entering the child node
        
        dfs(adjL, child, vis,ans);
        //Take action on after before exiting the child node
      }
      //take action on vertex before exiting the vertex
    
      // return  part for upward
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V+1,false);
        vector<int>ans;
        dfs(adj,0,vis,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends