//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
     int ans;
    
        int findForSubtree(Node* root, int dis) {
            if (root == nullptr || dis < 0) {
                return 0;
            }
            if (dis == 0) {
                return root->data;
            }
    
            return root->data + findForSubtree(root->left, dis - 1) + findForSubtree(root->right, dis - 1);
        }
    
        int solve(Node* root, int home, int k) {
            if (root == nullptr) {
                return -1;
            }
            if (root->data == home) {
                ans += findForSubtree(root, k);
                return 0;
            }
    
            int leftDistance = solve(root->left, home, k);
            int rightDistance = solve(root->right, home, k);
    
            if (leftDistance != -1) {
                if (leftDistance + 1 <= k) {
                    ans += root->data + findForSubtree(root->right, k - leftDistance - 2);
                }
                return leftDistance + 1;
            }
    
            if (rightDistance != -1) {
                if (rightDistance + 1 <= k) {
                    ans += root->data + findForSubtree(root->left, k - rightDistance - 2);
                }
                return rightDistance + 1;
            }
    
            return -1;
        }
    
        int ladoos(Node* root, int home, int k) {
            
            ans = 0;
            solve(root, home, k);
            return ans;
            
        }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends