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
    stack<TreeNode*> st;
    void inorder_func(TreeNode*root)
    {
        if(root == NULL)
            return;
        st.push(root);
        inorder_func(root->left);
        
    }
    BSTIterator(TreeNode* root) {
        inorder_func(root);
    }
    int next() {
        TreeNode*result = st.top();
        st.pop();
        inorder_func(result->right);
        return result->val;
    }
    bool hasNext() {
        if(!st.empty())
            return true;
        return false;
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