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
        if(lists.empty()) return NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(ListNode* i: lists){
            if(i!=NULL)
            pq.push(make_pair(i->val,i));
        }
        if(pq.empty()) return NULL;
        ListNode* head = pq.top().second;
        ListNode* current = head;
        if(head->next) pq.push(make_pair(head->next->val,head->next));
        pq.pop();
        while(!pq.empty()){
            ListNode* temp = pq.top().second;
            current->next = temp;
            pq.pop();
            if(temp->next) pq.push(make_pair(temp->next->val,temp->next));
            current = current->next;
        }
        return head;
        
    }
};