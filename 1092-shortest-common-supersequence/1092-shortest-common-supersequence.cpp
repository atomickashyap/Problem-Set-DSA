class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n =  str1.length();
        int m = str2.length();
        
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        
        for(int i =1;i<n+1;i++)
        {
            for(int j = 1;j<m+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    t[i][j] = t[i-1][j-1] +1;
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        int i = n,j = m;
        string ans;
        while(i>0 && j>0)
        {
            if(str1[i-1] == str2[j-1])
            {
                ans.push_back(str1[i-1]);
                i--;j--;
            }
            else{
                if(t[i][j-1] > t[i-1][j])
                {
                    ans.push_back(str2[j-1]);
                    j--;
                }
                else 
                {
                    ans.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        while(i>0)
		{
			ans.push_back(str1[i-1]);
			i--;
		}
		while(j>0)
		{
			ans.push_back(str2[j-1]);
			j--;
		}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};