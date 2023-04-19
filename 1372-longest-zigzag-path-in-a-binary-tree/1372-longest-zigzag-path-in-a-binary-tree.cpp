/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxpath =0;
    void preo(TreeNode* root, int curr, int parent, int path)
    {
        if(root == NULL)        
            return;        
        
        if(curr!=parent)                // root        
            path++;         // left child of right || vice-versa                       
        
        else if(parent!=0)
            path =1;        // 1 for the 1 edge that exists
        
        maxpath= max(path, maxpath);
        
        preo(root->left, -1, curr, path);       //left        
        preo(root->right, 1, curr, path);       //right
    }
    
public:
    int longestZigZag(TreeNode* root) 
    {              
        int path =0;
        preo(root, 0, 0, 0);    //void preo(root, int curr, int parent, int path)
        return maxpath;   
    }
};