/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* curr= head;
    struct ListNode* nxt = head->next;
    
    while(nxt!=NULL)
    {
        if(curr->val == nxt->val)
        {
            curr->next = nxt->next;
        }
        else{
            curr = nxt;
        }
        nxt= nxt->next;
    }
    
    
    return head;
}