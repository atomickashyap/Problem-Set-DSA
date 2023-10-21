class Solution {
private: 
    bool check_Diagonal(int i,int j, vector<vector<int>>&matrix){
                int n = matrix.size(),m = matrix[0].size();
            int k = i,l = j;
            int val = matrix[i][j];
        while(k<n && l<m)
        {
            if(matrix[k][l] == val)
            {
                k++;l++;
            }
            else
                return false;
        }
        
        
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        int i = 0;
        while(i<n)
        {
            if(check_Diagonal(i,0,matrix))
            {
                i++;
            }
            else{
                return false;
            }
        }
        int j = 0;
        while(j<m)
        {
            if(check_Diagonal(0,j,matrix))
            {
                j++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};