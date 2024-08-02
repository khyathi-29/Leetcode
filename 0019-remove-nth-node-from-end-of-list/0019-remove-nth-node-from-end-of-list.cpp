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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans=head;
        ListNode* nth=head;
        while(n>0)
        {
            nth = nth->next;
            n--;
        }
        if(nth==NULL) return head->next;
        while(nth->next!=NULL)
        {
            ans=ans->next;
            nth=nth->next;
        }
        
        if(ans->next!=NULL)
        {
            nth = ans->next->next;
        }
        ans->next = nth;
        
        return head;
    }
};