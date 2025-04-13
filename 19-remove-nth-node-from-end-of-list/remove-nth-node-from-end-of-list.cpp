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
        ListNode* temp = head;
        while(n>0){
            temp = temp->next;
            n--;
        }
        if(temp==NULL) return head->next;// we need to remove head
        ListNode* t1=head;
        ListNode* prev;
        while(temp!=NULL){
           temp = temp->next;
           prev = t1;
           t1=t1->next;
        }
        prev->next = t1->next;
        return head;
    }
};