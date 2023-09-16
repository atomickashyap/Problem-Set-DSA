/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return head;
    struct ListNode* pre = NULL;
    struct ListNode* curr = head;
    struct ListNode* ne = head->next;
    while(curr!=NULL)
    {
        curr->next = pre;
        pre = curr;
        curr = ne;
        if(ne !=NULL)
        {
            ne = ne->next;
        }
    }
    return pre;
}