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
    //length function 
    int length(ListNode * head)
    {
        int cnt = 0;
        while(head!=NULL)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA);
        int lenB = length(headB);
        
        while(lenA != lenB)
        {
            if(lenA>lenB)
            {
                headA = headA->next;
                lenA--;
            }
            else{
                headB = headB->next;
                lenB--;
            }
        }
        
        while(headA != NULL && headB != NULL)
        {
            if(headA == headB)
            {
                return headA;
            }
            headA= headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};