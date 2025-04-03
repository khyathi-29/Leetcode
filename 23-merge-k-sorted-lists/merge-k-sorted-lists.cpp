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
         for(auto it : lists){
            if(it!=NULL)
            pq.push({it->val,it});
         }
        
       while(!pq.empty()){
            auto temp = pq.top().second;
            cout<<pq.top().first<<endl;
            pq.pop();
            if(temp->next!=NULL) {
                pq.push({temp->next->val,temp->next});
            }
            ans->next = temp;
            ans = ans->next;

        }
        return temp->next;
        
    }
};