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
    vector<TreeNode*> f(int left,int right){

        vector<TreeNode*> res;

        //Base case 1:
        if(left>right){
            res.push_back(NULL);
            return res;
        }
        //Base case 2:
        if(left==right){
            TreeNode* node= new TreeNode(left);
            res.push_back(node);
            return res;
        }

        //Fix the root node in i
        for(int i=left; i<=right; i++){
        //The left subtree will have elements from the left bound till i-1
            vector<TreeNode*> leftSubtree=f(left,i-1);
        //The right subtree will have elements from i+1 till the right bound
            vector<TreeNode*> rightSubtree=f(i+1,right);
        //Add all possibilities of the combinations of the left subtrees and the right subtrees for the root node i
            for(int j=0; j<leftSubtree.size(); j++){
                for(int k=0; k<rightSubtree.size(); k++){
                    TreeNode* node=new TreeNode(i);
                    node->left=leftSubtree[j];
                    node->right=rightSubtree[k];
                    res.push_back(node);
                }
            }

        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return f(1,n);
    }
};