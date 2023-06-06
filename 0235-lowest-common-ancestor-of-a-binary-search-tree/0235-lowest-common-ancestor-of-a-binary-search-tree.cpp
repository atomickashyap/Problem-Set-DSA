/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* function(TreeNode* root, TreeNode* p, TreeNode*q)
    {
        if(root == NULL)
            return NULL;
        
        if(root->val == p->val || root->val == q->val)
        {
            return root;
        }
        
        TreeNode* lca1 = function(root->left,p,q);
        TreeNode* lca2 = function(root->right,p,q);
        
        if(lca1 != NULL && lca2 != NULL)
        {
            return root;
        }
        else if(lca1 != NULL)
            return lca1;
        else
            return lca2;
    }
    

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return function(root,p,q);
    }
};