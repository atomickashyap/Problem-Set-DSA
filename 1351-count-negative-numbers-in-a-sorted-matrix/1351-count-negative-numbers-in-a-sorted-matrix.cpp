class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0;i<m;i++)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(grid[i][j] <0)
                    ans++;
                else
                    break;
            }
        }
        
        
        
        return ans;
    }
};