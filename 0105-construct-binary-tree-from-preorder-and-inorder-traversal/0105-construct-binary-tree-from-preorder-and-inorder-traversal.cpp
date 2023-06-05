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
    TreeNode* createTree(vector<int>& preorder,int prestart , int preendd,vector<int>& inorder,  int instart, int inendd,map<int,int> &mp)
    {
        
        //base condition
        if(prestart > preendd || instart > inendd) return NULL;
        
        TreeNode*  root = new TreeNode(preorder[prestart]);
        int elem = mp[root->val];
        int nelem = elem - instart;
        
        root -> left = createTree(preorder, prestart + 1, prestart + nelem, inorder,
        instart, elem - 1, mp);
        root -> right = createTree(preorder, prestart + nelem + 1, preendd, inorder, 
        elem + 1, inendd, mp);
        
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int prestart = 0, preendd =  preorder.size()-1; // 0 based indexing
        int instart = 0, inendd = inorder.size()-1;
        
        map<int,int> mp;
        for(int i = instart; i<=inendd;i++)
        {
            mp[inorder[i]] = i; // key is element ->value is the index
        }
        
        return createTree(preorder,prestart,preendd,inorder,instart,inendd,mp);
        
    }
};