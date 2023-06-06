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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL) //base case
            return root;
        
        if(key < root->val) 
        {
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val)
        {
            root->right = deleteNode(root->right,key);
        }
        else
        {
            if(root->left == NULL && root->right == NULL) //case1 the root note is a leaf node
            {
                return NULL;
            }
            
            if(root->left == NULL || root->right == NULL) //case2 one of the child is null
            {
                if(root->left != NULL)
                    return root->left;
                else{
                    return root->right;
                }
            }
            
            TreeNode* temp = root->left;
            
            while(temp->right != NULL) temp = temp->right; //max value from the left subarray
            
            root->val = temp->val;
            root->left = deleteNode(root->left,temp->val);
            
        }
        
        
        
        
        
        return root;
    }
};