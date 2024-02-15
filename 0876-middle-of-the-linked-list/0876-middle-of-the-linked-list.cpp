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
    ListNode* middleNode(ListNode* head) {
       /* ListNode* t = head;
        int count=0;
        while(t!=NULL)
        {
            count++;
            t=t->next;
        }
        int mid = (count/2)+1;
        
        t=head;
        while(mid>1)
        {
            t=t->next;
            mid--;
        }
        return t;*/
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};