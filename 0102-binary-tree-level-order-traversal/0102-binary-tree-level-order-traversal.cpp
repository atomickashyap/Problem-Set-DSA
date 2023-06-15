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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int qsize = q.size();
            vector<int>temp;
            while(qsize--)
            {
                TreeNode* curr_root = q.front();
                q.pop();
                temp.push_back(curr_root->val);
                if(curr_root->left != NULL)
                {
                     q.push(curr_root->left);
                }
                if(curr_root->right != NULL)
                {
                     q.push(curr_root->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};