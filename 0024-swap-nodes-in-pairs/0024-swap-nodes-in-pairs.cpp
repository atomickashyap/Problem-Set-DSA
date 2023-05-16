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
    ListNode* swapPairs(ListNode* head) {
        if(head ==NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* ptr = head;
        while(head->next!=NULL)
        {
            swap(head->val,head->next->val);
            cout<<head->val<<" "<<head->next->val<<endl;
            if(head->next->next !=NULL)
            {
                head= head->next->next;
            }
            else{
                break;
            }
            
        }
        return ptr;
    }
};