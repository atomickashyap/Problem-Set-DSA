class Solution {
public:    
    int dp[2001][2001];
    int helper(int idx,vector<vector<int>>& preffix,int k){
        
        if(idx >= preffix.size() || k<=0){
            return 0;
        }
        
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }
        int max_score = INT_MIN;
        for(int i=0;i<=k && i<=preffix[idx].size();i++){
             int sum = 0;
            
             if(i>0){
                sum += preffix[idx][i-1];      
             }
           
             int score = helper(idx+1,preffix,k-i) + sum;
             max_score = max(max_score,score);   
        }
       
        return dp[idx][k] = max_score;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k){
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> preffix;
        for(int i=0;i<piles.size();i++){
            vector<int> v(piles[i].size());
            v[0] = piles[i][0];
            for(int j=1;j<piles[i].size();j++){
                v[j] = piles[i][j] + v[j-1];
            }
            preffix.push_back(v);
        }
        return helper(0,preffix,k);
    }
};