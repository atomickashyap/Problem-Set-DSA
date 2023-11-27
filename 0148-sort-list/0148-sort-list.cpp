/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        // return NULL;
        return merge(l1,l2);
    }
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        if(head1 == NULL)
            return head2;
        if(head2 == NULL)
            return head1;
        ListNode* l1 = head1;
        ListNode* l2 = head2;
        if(l1->val > l2->val)
            swap(l1,l2);
        
        ListNode* result = l1;
        
        while(l1!=NULL && l2 != NULL)
        {
            ListNode* temp = NULL;
            while(l1!=NULL && l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1,l2);
        }
        return result;
    }
};