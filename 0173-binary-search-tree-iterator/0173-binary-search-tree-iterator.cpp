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
class BSTIterator {
public:
    vector<int> inorder;
    int i = 0;
    void inorder_func(TreeNode*root)
    {
        if(root == NULL)
            return;
        inorder_func(root->left);
        inorder.push_back(root->val);
        inorder_func(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorder_func(root);
    }
    int next() {
        int result = inorder[i];
        i++;
        return result;
    }
    
    bool hasNext() {
        int temp = i;
        temp++;
        if(temp<=inorder.size()){
            return true;
        }
        else{
            return false;
        }
        
    }
};
         
// 0 1 2 3  4
// 3 7 9 15 20

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */