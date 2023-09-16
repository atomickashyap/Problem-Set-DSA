/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(head == NULL || k == 1)  return head;
    
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    
    struct ListNode* pre = dummy;
    struct ListNode* curr = dummy;
    struct ListNode*nxt = dummy;
    int cnt = 0;
    while(curr->next!=NULL)
    {
        cnt++;
        curr = curr->next;
    }
    while(cnt>=k)
    {
        curr = pre->next;
        nxt = curr->next;
        for(int i = 1;i<k;i++)
        {
            curr->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
            nxt = curr->next;
        }
        pre = curr;
        cnt-=k;
    }
    return dummy->next;
}