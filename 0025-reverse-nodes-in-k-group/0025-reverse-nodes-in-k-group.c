/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reverse(struct ListNode* s, struct ListNode* e)
{
    struct ListNode* pre = NULL;
    struct ListNode* curr = s;
    struct ListNode* nxt = s->next;
    
    while(pre!=e)
    {
        curr->next = pre;
        pre = curr;
        curr = nxt;
        if(nxt!=NULL)
            nxt = nxt->next;
    }
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(head == NULL || k ==1 || head->next == NULL)
        return head;
    
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    
    struct ListNode* beforestart = dummy;
    struct ListNode* end = head;
    int i = 0;
    while(end!=NULL)
    {
        i++;
        if(i%k==0)
        {
            //reverse
            struct ListNode* start= beforestart->next;
            struct ListNode* afterend = end->next;
            reverse(start,end);
            beforestart->next = end;
            start->next = afterend;
            beforestart = start;
            end = afterend;
            
        }
        else
        {
            end = end->next;
        }
    }
    
    
    
    
    
    
    return dummy->next;
}