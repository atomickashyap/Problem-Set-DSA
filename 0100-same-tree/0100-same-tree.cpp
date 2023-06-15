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
    void inorder(TreeNode* root,vector<int> &vec)
    {
        if(root == NULL)
        {
            vec.push_back(-1);
            return;
        }
        vec.push_back(root->val);
        inorder(root->left,vec);
        inorder(root->right,vec);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> inoP,inoQ;
        inorder(p,inoP);
        inorder(q,inoQ);
        if(inoP.size() != inoQ.size())
        
            return false;
        for(auto it:inoP)
        {
            cout<<it<<" ";
        }
        cout<<endl;
          for(auto it:inoQ)
        {
            cout<<it<<" ";
        }
        for(int i = 0;i<inoP.size();i++)
        {
            if(inoP[i] != inoQ[i])
                return false;
        }
        
        return true;
    }
};