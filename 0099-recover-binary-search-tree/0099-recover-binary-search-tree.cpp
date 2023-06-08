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
TreeNode* FirstWrong = NULL;
TreeNode* SecondWrong = NULL;
TreeNode* preNode = NULL;

private:
    void inorder(TreeNode* root)
    {
        if(root == NULL) //base case
            return;
        
        inorder(root->left);
        
        // we have to do some work
        
        if(preNode != NULL && (root->val < preNode->val ))
        {
            if(FirstWrong == NULL)
            {
                FirstWrong = preNode;
                SecondWrong = root;
            }
            else // if the node are not adjacent
                SecondWrong = root;
        }
        
        preNode = root;
        
        
        // work done
        inorder(root->right);
        
    }
    
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        swap(FirstWrong->val,SecondWrong->val);
        
    }
};