/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }
    struct ListNode* a = headA;
    struct ListNode* b = headB;
    
    while(a!=NULL || b!=NULL)
    {
        if(a == NULL)
            a = headB;
        if(b== NULL)
            b = headA;
        if(a == b)
            return a;
        a = a->next;
        b = b->next;
    }
    
    return a;
}