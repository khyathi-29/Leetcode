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
       ListNode* newHead = head;
       ListNode* ans = NULL;
       ListNode* prevTail=NULL;
        while(newHead!=NULL){
           if(kth(newHead,k)==true){
            ListNode* initialHead = newHead;
            ListNode* kthhead = reverse(newHead,k);
            if(!ans) ans = kthhead;
            if(prevTail) prevTail->next = kthhead;//connecting reversed segment to previous segment
            prevTail = newHead;
            newHead = initialHead->next;
           }
           else break;
        }
       return ans;
        
    }
    ListNode* reverse(ListNode* head, int k){
        ListNode* prev = NULL;
        ListNode* node = head;
        while(k--){
            ListNode* Next = node->next;
            node->next = prev;
            prev = node;
            node = Next;
        }
        head->next = node;//connecting reverse segment to next segment
        return prev;
    }
    bool kth(ListNode* head, int k){
        ListNode* temp = head;
        while(k!=0 && temp!=NULL){//1 3 //2 2 //3 1
            temp = temp->next;
            k--;
        }
        //cout<<temp->val<<endl;
        if(k==0) return true;
        else return false;
    }
    
};