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
        ListNode* prevGroup = dummy;
         while(temp!=NULL)
         {
            int n = k;
            ListNode* temp1 = temp;
            while(n!=0)
            {
                if(temp1==NULL) return dummy->next;
                temp1 = temp1->next;
                n--;
            }
            ListNode* nextGroup = temp1;
            ListNode* prevHead = temp;
            ListNode* newHead = reverse(temp,k);
            cout<<"fjurf"<<prevGroup->val<<endl;
            prevGroup->next = newHead;
            prevHead->next = nextGroup;
            prevGroup = temp;
            temp = temp1;
         }

         return dummy->next;
    }
    ListNode* reverse(ListNode* head,int n)
    {
      ListNode* prev = NULL;
      ListNode* current = head;
      ListNode* Nnext ;
      while(n!=0){
        Nnext = current->next;
        current->next = prev;
        prev = current;
        current = Nnext;
        n--;
      }
      return prev;
    }
};