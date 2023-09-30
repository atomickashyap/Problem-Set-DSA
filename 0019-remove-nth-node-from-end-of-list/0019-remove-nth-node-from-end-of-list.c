/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* dummy = (struct ListNode* ) malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode* slow = dummy;
    struct ListNode* fast = dummy;
    
    while( n-- && fast->next !=NULL )
    {
        fast = fast->next;
    }
    if(n>0)
    {
        printf("asd");
        return head->next;
    }
    while(fast->next!=NULL)
    {
        fast= fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    
    return dummy->next;
}