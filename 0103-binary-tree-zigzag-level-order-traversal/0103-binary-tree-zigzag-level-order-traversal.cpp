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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool check = false;
        while(!q.empty())
        {
            int q_size = q.size();
            vector<int> temp;
            while(q_size--)
            {
                TreeNode* q_root = q.front();
                temp.push_back(q_root->val);
                q.pop();
                if(q_root->left != NULL)
                {
                    q.push(q_root->left);
                }
                if(q_root->right != NULL)
                {
                    q.push(q_root->right);
                }
            }
            if(check)
                {
                    reverse(temp.begin(),temp.end());
                    check = false;
                }
                else
                    check = true;
            ans.push_back(temp);
        }
        return ans;
    }
};