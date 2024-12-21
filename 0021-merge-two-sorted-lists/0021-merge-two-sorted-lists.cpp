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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if(list1==NULL) return list2;
      if(list2==NULL) return list1;
      if(list1->val > list2->val) return mergeTwoLists(list2,list1);
      ListNode* ans = list1;
      ListNode* prevl1;
      while(list1!=NULL and list2!=NULL)
      {
        if(list1->val <= list2->val)
        {
            prevl1 = list1;
            list1=list1->next;
        }
        else
        {
            ListNode* temp = list1;
            list1 = list2;
            prevl1->next = list2;
            list2 = temp;
             
        }
      }
      prevl1->next = list2;
      return ans;  
    }
};