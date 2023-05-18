//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    
    
   bool helper(int i , int j , vector<vector<int>>& arr){
       
       if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size()){
           return true;
       }
       
       
       if(arr[i][j]==0)return true;
       if(arr[i][j]==1){
           arr[i][j]=0;
           if((i==0) || j==0 || i==arr.size()-1 || j==arr[0].size()-1){

//ITS BASICALLY FOR TRAVERSING THROUGH ITS ADJACENTS INORDER TO CONVERT ALL THE ADJACENTS TO ZERO (BOOL f is of no use i just wanted to traverse the adjacents ) 

                bool f = helper(i+1 , j ,arr); 
                 f= helper(i-1,j,arr);
                 f = helper(i,j+1,arr);
                 f = helper(i,j-1,arr);
                 return false;
           }
           else{
                 bool f = helper(i+1 , j ,arr);
                 bool ff= helper(i-1,j,arr);
                 bool fff = helper(i,j+1,arr);
                 bool ffff = helper(i,j-1,arr);
                 return f&& ff&&fff&&ffff;
           }
          
           
       }
   }
    int closedIslands(vector<vector<int>>& arr, int n, int m) {
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++ ){
                if(arr[i][j]==1){
                    if(helper(i,j,arr)){
                        ans++;
                    }
                }
            }
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends