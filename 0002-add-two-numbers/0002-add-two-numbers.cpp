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
    int sum_ofLL(ListNode* l1, ListNode* l2)
    {
        int sum = 0;
        if(l1 != NULL)
        {
            sum+=l1->val;
        }
        if(l2!=NULL)
        {
            sum+=l2->val;
        }
        return sum;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        int sum =0;
        int carry = 0;
        while(l1!=NULL || l2!=NULL)
        {
            sum =0;
            sum = sum_ofLL(l1,l2)+carry;
            carry = 0;
            if(sum<10)
            {
                ListNode* dummy = new ListNode(sum);
                temp->next = dummy;
                temp = temp->next;
            }
            else{
                ListNode* dummy = new ListNode(sum%10);
                carry = sum/10;
                temp->next = dummy;
                temp = temp->next;
            }
            if(l1!=NULL)
                l1 = l1->next;
            if(l2!=NULL)
                l2 = l2->next;
        }
        if(carry!=0)
        {
            ListNode* dummy = new ListNode(carry);
                temp->next = dummy;
                temp = temp->next;
        }
        
        return res->next;
    }
};