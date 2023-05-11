class Solution {
public:
    int help(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&v)
    {
        if(i>=nums1.size()||j>=nums2.size())
        return 0;
        if(v[i][j]!=-1)
        return v[i][j];
        if(nums1[i]==nums2[j])
        v[i][j]=1+help(i+1,j+1,nums1,nums2,v);
        else
        v[i][j]=max(help(i,j+1,nums1,nums2,v),help(i+1,j,nums1,nums2,v));
        return v[i][j];
    }
        int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
          int n1=nums1.size();
          int n2=nums2.size();
          vector<vector<int>>v(n1+1,vector<int>(n2+1,-1));
          return help(0,0,nums1,nums2,v);
        }
};