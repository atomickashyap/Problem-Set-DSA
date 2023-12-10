class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> trans(m,vector<int>(n,0));
        int j= 0;
        for(auto it:matrix)
        {
            int i=0;
            for(auto element: it)
            {
                trans[i][j]= element;
                i++;
            }
            j++;
        }
        return trans;
    }
};