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
    bool length(ListNode* head, int k)
    {
        while(k and head)
        {
            head = head->next;
            k--;
        }
        return k==0;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *prev=NULL, *forward, *first = head;
        if(k==1) return head;
        if(!length(head, k)) return head;

        for(int i=0;i<k;i++)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        // curr->next = NULL;
        head = prev;
        first->next = reverseKGroup(forward, k);
        return head;
    }
};