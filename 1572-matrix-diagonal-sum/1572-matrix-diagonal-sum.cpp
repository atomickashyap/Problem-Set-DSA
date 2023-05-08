class Solution {
public:
    int diagonalSum(vector<vector<int>>& v) {
        
        int n = v.size()-1;
        long long sum = 0;
        
        int i = 0,j = 0;
        while(i<=n)
        {
            sum+=v[i][j];
            i++;j++;
        }
        i = 0;j=n;
        while(i<=n)
        {
            if(i==j)
            {
                i++;j--;
                continue;
            }
            sum+=v[i][j];
            i++;j--;
        }
        return sum;
        
    }
};