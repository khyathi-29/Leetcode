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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* dummy = ans;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int val = carry;
            if(l1!=NULL) {
                val+= l1->val; 
                l1=l1->next;
            }
            if(l2!=NULL) {
                val+= l2->val; 
                l2=l2->next;
            }
            carry = val/10;
            val = val%10;
            ListNode* temp = new ListNode(val);
            dummy->next = temp;
            dummy=dummy->next;
        }
        return ans->next;
        
    }
};