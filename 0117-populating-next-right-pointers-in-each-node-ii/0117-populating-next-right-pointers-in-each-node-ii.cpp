/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                auto p = q.front();
                q.pop();
                if(n==0)
                    p->next = NULL;
                else
                    p->next = q.front();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return root;
    }
};