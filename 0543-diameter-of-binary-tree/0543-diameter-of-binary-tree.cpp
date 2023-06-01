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
    int diameter_tree(TreeNode* root, int &diameter)
    {
        if(root == NULL)
            return 0;
        
        int left = diameter_tree(root->left,diameter);
        int right = diameter_tree(root->right,diameter);
        
        diameter = max(diameter,left+right); //case1
        return max(left,right)+1; //case2
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameter_tree(root, diameter);
        return diameter;
    }
};