/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middle(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast->next!=NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
struct LinkNode* reverse(struct ListNode* head)
{
    struct ListNode* pre = NULL;
    struct ListNode* next_head = NULL;
    while(head!=NULL)
    {
        next_head = head->next;
        head->next = pre;
        pre = head;
        head = next_head;
        
    }
    return pre;
}
bool isPalindrome(struct ListNode* head){
    if(head->next == NULL || head == NULL)
        return true;
    struct ListNode* slow = middle(head);
    // slow = slow->next;
    slow->next = reverse(slow->next);
    slow= slow->next;
    struct ListNode* dummy = head;
    while(slow!=NULL)
    {
        if(dummy->val !=slow->val)
            return false;
        slow = slow->next;
        dummy = dummy->next;
    }
    
    return true;
}