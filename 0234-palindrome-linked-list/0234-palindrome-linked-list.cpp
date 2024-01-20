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
private:
    ListNode* find_middle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next !=NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
            
    }
    ListNode * reverse(ListNode* head)
    {
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* nxt = head->next;
        while(curr!=NULL)
        {
            curr->next = pre;
            pre = curr;
            curr = nxt;
            if(nxt !=NULL)
                nxt = nxt->next;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* dummy = head;
        ListNode* slow = find_middle(dummy);
        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode* temp = head;
        while(slow!=NULL)
        {
            if(temp->val != slow->val)
            {
                return false;
            }
            slow = slow->next;
            temp = temp->next;
        }
        
        return  true;
    }
};