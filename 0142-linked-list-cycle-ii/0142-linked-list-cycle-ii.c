/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* meet(struct ListNode* start, struct ListNode* head)
{
    struct ListNode* entry = head;
    while(entry != start)
    {
        start = start->next;
        entry = entry->next;
    }
    return start;
}
struct ListNode *detectCycle(struct ListNode *head) {
    
    if(head == NULL || head->next == NULL)
        return NULL;
    
    struct ListNode* fast,*slow;
    fast = slow = head;
    
    while(fast->next!= NULL && fast->next->next!= NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return meet(slow,head);
        
    }
    
    return  NULL;
}