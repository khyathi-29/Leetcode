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
    ListNode* reverseKGroup(ListNode* head, int k) {
     ListNode* dummy = new ListNode(0,head);
     ListNode* temp = head;
     ListNode* prevHead = dummy;
     while(temp!=NULL)
     {
        ListNode* temp1 = temp;
        int n = k;
        while(n!=0)
        {
            if(temp1==NULL) return dummy->next;
            temp1 = temp1->next;
            n--;
        }
        ListNode* oldstart = temp;
        ListNode* newstart = Reverse(temp,k);

        prevHead->next = newstart;
        prevHead = oldstart;
        oldstart->next = temp1;
        temp = temp1;
     }
        return dummy->next;

    }
    ListNode* Reverse(ListNode* temp, int k)
    {
        ListNode* te = temp;
        ListNode* pre = NULL;
        ListNode* Next;
        while(k!=0)
        {
            Next = te->next;
            te->next = pre;
            pre = te;
            te = Next;
            k--;
        }

        return pre;
    }
    
};