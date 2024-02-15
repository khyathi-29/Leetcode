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
        ListNode* head = list1;
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        if(list1->val > list2->val)
        {
            ListNode* a = list1;
            list1 = list2;
            list2 = a;
        }
        ListNode* ans=list1;
        
        while(list1!=NULL && list2!=NULL)
        {
            ListNode* temp;
            if(list1!=NULL && list1->val <= list2->val)
            {
                temp=list1;
                list1=list1->next;
            }
            temp->next = list2;
            ListNode* a = list1;
            list1 = list2;
            list2 = a;
            
        }
        return ans;
        
        
       /* if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        int a=0;
        if(list1->val > list2->val)
        {
            a= list2->val;
            list2=list2->next;
        }
        else
        {
            a=list1->val;
            list1=list1->next;
        }
        ListNode* head = new ListNode(a);
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* l3 = head;
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val > l2->val)
            {
                ListNode* temp = new ListNode(l2->val);
                l3->next = temp;
                l3=l3->next;
                l2=l2->next;
            }
            else
            {
                ListNode* temp = new ListNode(l1->val);
                l3->next = temp;
                l3=l3->next;
                l1=l1->next;
            }
        }
        while(l1!=NULL){
            ListNode* temp = new ListNode(l1->val);
                l3->next = temp;
                l3=l3->next;
                l1=l1->next;
            
        }
        while(l2!=NULL)
        {
            ListNode* temp = new ListNode(l2->val);
                l3->next = temp;
                l3=l3->next;
                l2=l2->next;
        }
        return head;*/
        
    }
};