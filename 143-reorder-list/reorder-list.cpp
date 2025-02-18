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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        // getting middle element
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;// so that connection cut at half
        //reversing from middle element
        ListNode* prev = NULL;
        ListNode* current = mid;
        while(current!=NULL){
            ListNode* Next = current->next;
            current->next = prev;
            prev = current;
            current = Next;

        }
       ListNode* node2 = prev;// gives the reverse of LL starting with end element
       ListNode* node1 = head;

       while( node1!=NULL && node2!=NULL){
        ListNode* temp1 = node1->next;
        ListNode* temp2 = node2->next;
        node1->next = node2;
        node1 = temp1;
        node2->next = node1;
        node2 = temp2;
       }
           
    }
};