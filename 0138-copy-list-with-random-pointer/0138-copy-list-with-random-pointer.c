/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if(head == NULL)
        return head;
    struct Node* itr = head;
    struct Node* front = head;
    //step 1 make deep copy and place in original
    while(itr!=NULL)
    {
        front = front->next;
        struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
        newnode->val = itr->val;
        newnode->next = front;
        itr->next = newnode;
        itr = front;
        
    }
    
//     step 2
    itr = head;
    while(itr!=NULL)
    {
        
        if (itr->random != NULL) {
              itr->next->random = itr->random->next;
            }
        else{
            itr->next->random = NULL;
        }
        itr = itr->next->next;
    }
    
    //retriving back 
    itr = head;
    struct Node* dummy = (struct Node* ) malloc(sizeof(struct Node)); 
    dummy->val = -1;
    struct Node* copy = dummy;
    while(itr!=NULL)
    {
            front = itr->next->next;
            // extract the copy
            copy->next = itr->next;
            // restore the original list
            itr->next = front;
            copy = copy -> next; 
            itr = front;
    }
    return dummy->next;
}