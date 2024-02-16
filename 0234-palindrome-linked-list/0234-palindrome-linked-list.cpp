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
    bool isPalindrome(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       if(head==NULL || head->next==NULL)
       {
           return true;
       }
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* reversehead=slow->next;
        slow->next=NULL;
        reversehead = reverse(reversehead);
        while(reversehead!=NULL && head!=NULL )
        {
            if(reversehead->val!=head->val)
            {
                return false;
            }
            reversehead=reversehead->next;
            head=head->next;
        }
        
        return true;
    }
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* current = head;
        ListNode* back = NULL;
        while(current!=NULL)
        {
            ListNode* front = current->next;
            current->next = back;
            back = current;
            current = front;
        }
        return back;
    }
};  