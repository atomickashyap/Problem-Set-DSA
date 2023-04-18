//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c) 
    {
        vector<int> ans;
       // int r=m.size();
       // int c=m[0].size();
        
        int count=0;
        int total=r*c;
        
        int startRow=0;
        int startCol=0;
        int endCol=c-1;
        int endRow=r-1;
        
        
        while(count<total){
            
            for(int i=startCol;count<total&&i<=endCol;i++){
               ans.push_back(m[startRow][i]);
                count++;
            }
            startRow++;
            for(int i=startRow;count<total&&i<=endRow;i++){
                ans.push_back(m[i][endCol]);
                count++;
            }
            endCol--;
            for(int i=endCol;count<total&&i>=startCol;i--){
                ans.push_back(m[endRow][i]);
                count++;
            }
            endRow--;
            for(int i=endRow;count<total&&i>=startRow;i--){
                ans.push_back(m[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends