class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        for(int i=1; i<m ; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]!=0)
                    mat[i][j]+=  mat[i-1][j];
            }
        }
        int ans=0;
        for(int i=0; i<m; i++){
            sort(mat[i].begin(), mat[i].end(), greater<int>());
            for(int j=0; j<n; j++){
                ans= max(ans, mat[i][j]*(j+1));
            }
        }
        return ans;
    }
};