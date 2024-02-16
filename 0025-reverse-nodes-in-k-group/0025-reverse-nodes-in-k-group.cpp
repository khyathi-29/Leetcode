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
        ListNode* temp = head;
        ListNode* newhead = head;
        ListNode* prevlast = NULL;// lastnode of previous k series
        while(temp!=NULL)
        {
            ListNode* KNode = KthNode(temp,k);
            if(KNode==NULL)
            {
                if(prevlast!=NULL)
                {
                    prevlast->next=temp;
                }
                break;
            }
            ListNode* nextnode= KNode->next;
            KNode->next=NULL;
            reverse(temp);
            if(temp == head)
            {
                newhead=KNode;
            }
            else{
                prevlast->next = KNode;
            }
            prevlast = temp;
            temp = nextnode;
        }
        return newhead;
        
    }
    ListNode* reverse(ListNode* head)
    {
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
    ListNode* KthNode(ListNode* head,int k)
    {
        ListNode* a = head;
        k=k-1;
        while(a!=NULL && k>0)
        {
            a=a->next;
            k--;

        }
        return a;
    }
};