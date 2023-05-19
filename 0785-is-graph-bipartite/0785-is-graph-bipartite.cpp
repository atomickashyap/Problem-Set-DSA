class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();

		vector<int> vis(n, 0);

		queue<int> q;

		for(int i=0; i<n; i++){
			if(vis[i])
				continue;

			vis[i] = 1;
			q.push(i);

			while(!q.empty()){
				int node = q.front();
				q.pop();

				for(int j:graph[node]){
					if(vis[j] == vis[node])
						return false;
					if(!vis[j]){
						vis[j] = -vis[node];
						q.push(j);
					}
				}
			}
		}
		return true;
	}
};