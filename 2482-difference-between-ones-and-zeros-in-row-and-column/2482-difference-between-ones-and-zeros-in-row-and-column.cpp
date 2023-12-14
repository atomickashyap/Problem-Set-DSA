class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r = grid[0].size();
        int c = grid.size();
        cout<<r <<" "<<c;
        vector<int> row(c,0);
        vector<int> col(r,0);
        
        for(int i = 0;i<c;i++)
        {
            for(int j = 0;j<r;j++)
            {
                row[i]+=grid[i][j];
            }
        }
        for(int i = 0;i<c;i++)
        {
            for(int j = 0;j<r;j++)
            {
                col[j]+=grid[i][j];
            }
        }
        for(int i = 0;i<c;i++)
        {
            for(int j = 0;j<r;j++)
            {
                grid[i][j] = row[i]+col[j] - (r-row[i]) - (c - col[j]);
            }
        }
    
        
        
        
        
        return grid;
    }
};