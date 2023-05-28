/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* itr = head;
        Node* front = head;
        
        while(itr!= NULL) //make a copy node and inserting in between the original list (Orignal -> cpy ->Orignal)
        {
            front = itr->next;
            Node *copy  = new Node(itr->val);
            itr->next = copy;
            copy->next = front;
            itr = front;
        }
        
        itr =head;
        while(itr!=NULL) // seting the random of copy node 
        {
            if(itr->random != NULL)
            {
                itr->next->random = itr->random->next;
                
            }
            itr = itr->next->next;
        }
        itr= head;
        Node* temp_head  = new Node(INT_MIN);
        Node* copy_node = temp_head;
        while(itr!=NULL)
        {
            front = itr->next->next;
            copy_node->next = itr->next;
            itr->next = front;
            copy_node = copy_node->next;
            itr = itr->next;
        }
        
        return temp_head->next;
    }
};