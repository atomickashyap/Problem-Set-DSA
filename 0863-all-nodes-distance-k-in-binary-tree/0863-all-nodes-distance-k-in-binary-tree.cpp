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
    vector<int> adj[501];
private:
    void makegraph(TreeNode* root)
    {
        if(root == NULL)
            return;
        if(root->left!=NULL)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right !=NULL)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        makegraph(root->left);
        makegraph(root->right);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans; 
        if(k ==0)
        {
            ans.push_back(target->val);
            return ans;
        }
        makegraph(root);
        queue<int>q;
        int flag =0,level = 0;
        vector<bool> vis(501,false);
        vis[target->val] = true;
        q.push(target->val);
        while(!q.empty())
        {
            int n = q.size();
            level++;
            for(int i = 0;i<n;i++)
            {
                int child = q.front();
                q.pop();
                for(auto it : adj[child])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it] = true;
                        if(k == level)
                        {
                            ans.push_back(it);
                            flag = 1;
                        }
                    }
                }    
            }
            if(flag == 1)
                return ans;
            
        }
        return ans;
    }
};