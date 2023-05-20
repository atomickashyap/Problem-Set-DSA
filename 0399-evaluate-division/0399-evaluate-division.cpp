class Solution {
public:
    
    void dfs(string &source, string &destination, unordered_map<string,vector<pair<string,double>>>&graph, unordered_map<string,int>&vis, double &ans, double temp)
    {
        if(vis.count(source))return;//if node is present in the visited map then we need to return directly
        
        vis[source]++;//mark the source as visited 
        if(source==destination)//// If source and dest node are equal then update the ans and return back
        {
            ans=temp;
            return;
        }
        
        for(auto it:graph[source])
        {
            dfs(it.first,destination,graph,vis,ans,temp*it.second);////update temp to temp multiply by the edge weight between node to adjNode as if a->b is 2.0 and b->c is 3.0 then a->c will be 2.0*3.0
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //create a graph first
        unordered_map<string,vector<pair<string,double>>>graph; //{source,{destination,edge weight}}
        
        for(int i=0; i<equations.size(); i++)
        {
            graph[equations[i][0]].push_back({equations[i][1],values[i]});
            graph[equations[i][1]].push_back({equations[i][0],1/values[i]});//here if a->b has weight 2.0 implies that b->a will have weight 1/2.0=0.5
        }
        
        vector<double>res(queries.size());
        unordered_map<string,int>vis;//to store the visited string in each dfs call
        
        for(int i=0; i<queries.size(); i++)
        {
            string start=queries[i][0],end=queries[i][1];
            double ans=-1.0;//initialize ans as -1.0
            
            vis.clear();//clear the visted map for each dfs call
            if(graph.count(start))dfs(start,end,graph,vis,ans,1.0);//if node is present in the graph then only we have to call the dfs
            
            res[i]=ans;
        }
        
        return res;
    }
};