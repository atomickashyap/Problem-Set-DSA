class Solution {
public:
    double knightProbability(int n, int k, int row, int column) 
 {
		map<pair<int,int>,double> curr_map;
        map<pair<int,int>,double> next_map;
        queue<pair<int,int>> q;  
        curr_map[{row,column}]=1.0;
        int kk=k;
        q.push({row,column});
        vector<vector<int>> moves = {{-2,1},{-2,-1},{-1,2},{-1,-2},{2,-1},{2,1},{1,2},{1,-2}};
        while(!q.empty())
        {   
            if(kk==0)
            {
                break;
            } 
            
            int s=q.size();
            while(s--)
            {
                auto t=q.front();
                q.pop();
                for(auto in:moves)
                {
                    int x=t.first+in[0];
                    int y=t.second+in[1];
                    if(x>=0 and y>=0 and x<n and y<n)
                    {
                        if(next_map.find({x,y})==next_map.end())
                        {
                            q.push({x,y});   
                        }
                        
                        next_map[{x,y}]+=curr_map[{t.first,t.second}]/8.0;
                        
                    }
                } 
            }
            
            curr_map=next_map;
            next_map.clear();
            kk--;        
        }
        
        double prob;
        for(auto in:curr_map)
        {
            prob+=in.second;
        }
        return prob;
	}
};