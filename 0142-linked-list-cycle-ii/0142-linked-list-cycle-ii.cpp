/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* find_node(ListNode*slow,ListNode*head)
    {
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout<<"Asdf";
                return find_node(fast,head);
            }
            
        }
        
        return NULL;
    }
};
