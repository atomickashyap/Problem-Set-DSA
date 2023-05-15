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
    int length_ll(ListNode* ptr)
    {
        int sum= 0;
        while(ptr)
        {
            sum++;
            ptr= ptr->next;
        }
        return sum;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        int len = length_ll(head);
        ListNode* swap1;
        swap1 = head;
        for(int i = 1;i<k;i++)
        {
            swap1 = swap1->next;
        }
        ListNode* swap2;
        swap2 = head;
        for(int i = 1;i<(len-k+1);i++)
        {
            swap2=swap2->next;
        }
        int temp = swap1->val;
        // cout<<ptr->val;
        swap1->val = swap2->val;
        swap2->val = temp;
        
        
        
        return head;
    }
};