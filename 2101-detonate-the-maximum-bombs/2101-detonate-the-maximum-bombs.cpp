class Solution {
public:
    int distance(int x, int y, int x1, int y1)
    {
        double temp = sqrt(pow(x1-x,2) + pow(y1-y,2));
        return ceil(temp);
    }
    
    int dfs(int index, vector<int> &visited, vector<vector<int>> &graph)
    {
        int temp = 1;
        visited[index] = 1;
        for(auto x : graph[index])
        {
            if(visited[x] == 0)
            {
                temp += dfs(x,visited,graph);
            }
        }
        return temp;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                int x = bombs[i][0];
                int y = bombs[i][1];
                int x1 = bombs[j][0];
                int y1 = bombs[j][1];
                int r = bombs[i][2];
                int r1 = bombs[j][2];
                int temp = distance(x,y,x1,y1);
                if(temp <= r)
                {
                    graph[i].push_back(j);
                }
                if(temp <= r1)
                {
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> visited;
        vector<int> x(n,0);
        int ans = 1;
        for(int i = 0 ; i < n ; i++)
        {
            visited = x;
            int temp = dfs(i,visited,graph);
            ans = max(ans,temp);
        }
        return ans;
    }
};