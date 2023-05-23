/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;// slow pointer
        ListNode * fast = head;// fast pointer
        
        while(fast!=NULL and fast->next!=NULL) //if we did not find any loop it terminates
        {
            slow = slow ->next; // increament by 1
            fast = fast->next->next;// increment by 2
            
            if(slow == fast) // that is both the point meet 
            {
                return true;
            }
        }
        
        
        return false; //didnot detect any loop
    }
};