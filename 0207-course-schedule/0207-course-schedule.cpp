class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& graph) {
        int m= graph.size();
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(int i=0; i<m; i++){
            int node1= graph[i][0];
            int node2= graph[i][1];
            adj[node2].push_back(node1);
            indegree[node1]++;
            
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node= q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==n) return true;
        return false;
    }
};