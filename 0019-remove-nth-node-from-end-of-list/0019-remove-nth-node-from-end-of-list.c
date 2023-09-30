/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int len = 0;
    struct ListNode* dummy = head;
    while(dummy!=NULL)
    {
        dummy = dummy->next;
        len++;
    }
    len = len-n;
    if(len ==0)
        return head->next;
    dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    
    while(len--)
    {
        dummy= dummy->next;
    }
    printf("%d",dummy->val);
    
    if(dummy->next!=NULL)
        dummy->next = dummy->next->next;
    else{
        dummy->next = NULL;
    }
    
    return head;
}