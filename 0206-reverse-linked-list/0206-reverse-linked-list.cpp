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
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = head;
        ListNode* prev = NULL ;
        ListNode* next;
        while(ans!=NULL)
        {
            next = ans->next;
            ans->next = prev;
            prev = ans;
            ans = next;

        }
        return prev;
    }
};