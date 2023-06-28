class Solution {
public:
        double maxProbability(int n, vector<vector<int>>& vec, vector<double>& succProb, int start, int end) {
             vector<pair<int ,double >> graph[n];
        for(int i = 0;i<vec.size();i++)
        {
            graph[vec[i][0]].push_back({vec[i][1],succProb[i]});
            graph[vec[i][1]].push_back({vec[i][0],succProb[i]});
        }
        vector<double> dis(n,INT_MIN);

        for(int i = 0 ;i<n;i++)
        {
            if(dis[i] == INT_MIN)
            {
                queue<int> q;
                q.push(start);
                dis[start] =1;
                while(!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    for(auto it: graph[curr])
                    {
                        double temp = it.first,weight = it.second;
                        if(dis[curr] * weight > dis[temp])
                        {
                            dis[temp] = dis[curr] * weight;
                            q.push(temp);
                        }
                    }

                }
            }
        }
        if(dis[end] !=INT_MIN)
            return dis[end];
        return 0.000;
    }
};