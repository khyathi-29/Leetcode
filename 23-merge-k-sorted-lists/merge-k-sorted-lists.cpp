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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
     ListNode* temp = new ListNode();
     ListNode* ans = temp;
     for( ListNode* t : lists)
     {
        if(t!=NULL) pq.push(make_pair(t->val,t));
     }
     while(!pq.empty())
     {
        ListNode* tt = pq.top().second;
        pq.pop();
        temp->next = tt;
        temp = temp->next;
        if(tt->next!=NULL) pq.push(make_pair(tt->next->val,tt->next));

     }
      return ans->next;
    }
};