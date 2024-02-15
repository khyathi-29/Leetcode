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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int len1 =0;
        int len2 =0;
        ListNode* t1= l1;
        ListNode* t2= l2;
        vector<int> a;
        while(t1!=NULL)
        {
            len1++;
            t1=t1->next;
        }
        while(t2!=NULL)
        {
            len2++;
            t2=t2->next;
        }
        
        int len = min(len1,len2);
        int l=0;
        if(len1>len2)
        {
            t1=l1;
            t2=l2;
            l=len1-len2;
        }
        else
        {
            t1=l2;
            t2=l1;
            l=len2-len1;
        }
        int k=0;
        while(len>0)
        {
          int i = t1->val + t2->val+k;
          if(i>9)
          {
              k=1;
          }
          else
          {
              k=0;
          }
          a.push_back(i%10);
          i=0;
          t1=t1->next;
          t2=t2->next;
          len--;
        }
        while(l>0)
        {
            int i = t1->val + k;
          if(i>9)
          {
              k=1;
          }
          else
          {
              k=0;
          }
          a.push_back(i%10);
          i=0;
          t1=t1->next;
          l--;
        }
        if(k==1)
        {
            a.push_back(1);
        }
        cout<<len1<<len2;
        ListNode* head= new ListNode(a[0]);
        ListNode* temp = head;
        for(int i=1;i<a.size();i++)
    {
        ListNode *val = new ListNode(a[i]);
        temp->next = val;
        temp = temp->next;
    }
       return head; 
    }
};