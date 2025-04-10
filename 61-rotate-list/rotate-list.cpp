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
    ListNode* rotateRight(ListNode* head, int k) {
        int length=0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        if(length==0) return NULL;
        k = k%length;
        if(k==0) return head;
        k = length-k;
        temp =head;
        while(k>1)
        {
            temp=temp->next;
            k--;
        }
        ListNode* newHead = temp->next;
        temp->next=NULL;
        temp = newHead;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = head;
        return newHead;
    }
};