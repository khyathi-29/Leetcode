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
    ListNode* reverseLinkedList(ListNode* head)
    {
        ListNode* current = head;
        ListNode* prev = NULL;
        while(current!=NULL)
        {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
          return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast =head;
        ListNode* prev;
        if(head->next==NULL) return true;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            prev = slow;
            slow=slow->next;
        }
        prev->next=NULL;
        fast = head;
        slow=reverseLinkedList(slow);
        while(fast!=NULL && slow!=NULL)
        {
            if(slow->val == fast->val)
            {
                slow=slow->next;
                fast=fast->next;
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};