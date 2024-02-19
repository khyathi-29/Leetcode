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
        
        ListNode* first = head;
        int length = 0;
        if(first==NULL)
        {
            return head;
        }
        while(first!=NULL)
        {
            first=first->next;
            length++;
        }
        if(length==1)
        {
            return head;
        }
        k=k%length;
        if(k==0)
        {
            return head;
        }
        k =length-k;
        cout<<"kkk"<<k;
        first = head;
        if(k==0)
        {
            return head;
        }
        while(k>1 && first!=NULL)
        {
            if(first->next==NULL)
            {
                first=head;
            }
            else
            {
            first=first->next;
            }
            k--;
        }
        ListNode* second = first->next;
        first->next = NULL;
        ListNode* temp = second;
        cout<<second->val<<" ";
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = head;


        return second;
    }
};