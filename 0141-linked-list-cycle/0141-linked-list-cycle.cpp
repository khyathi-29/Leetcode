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
        ListNode* slow;
        ListNode* fast;
        slow = head;
        fast = head;
        if(head==NULL)
        {
            return false;
        }
        if(head->next==NULL)
        {
            return false;
        }
        
        slow = slow->next;
        fast = fast->next->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            if(slow == fast)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
        
    }
};