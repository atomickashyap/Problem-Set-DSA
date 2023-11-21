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
    void preorder(TreeNode* root,vector<int>&pre)
    {
        if(root == NULL)
            return;
        
        pre.push_back(root->val);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
    void constructTree(vector<int>&pre,TreeNode* root)
    {
        TreeNode*preNode = root;
        for(auto it: pre)
        {
            if(root==NULL){
                root = new TreeNode(it);
                preNode->right = root;
                cout<<root->val<<" ";
            }
            else{
                root->val = it;
            }
            root->left = NULL;
            preNode = root;
            root = root->right;
        }
    }
public:
    void flatten(TreeNode* root) {
        vector<int> pre;
        preorder(root,pre);
        
        constructTree(pre,root);
    }
};