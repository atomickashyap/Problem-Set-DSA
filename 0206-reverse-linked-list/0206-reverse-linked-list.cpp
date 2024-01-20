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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* nxt = head->next;
        while(curr!=NULL)
        {
            curr->next = pre;
            pre = curr;
            curr = nxt;
            if(nxt!=NULL)
                nxt = nxt->next;
        }
        return pre;
    }
};

// 1->2->3->4->
// null->1->2->3
// p     c   n

// c->p
// p = c
// c = n
// n->next;
// null<-1  2->3
//       p,c n

