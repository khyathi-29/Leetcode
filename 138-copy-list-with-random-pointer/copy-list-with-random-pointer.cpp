/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp; // maps old list to its corresonding new list
        if(head ==NULL ) return NULL;
        Node* oldhead = head;
        Node* ans = new Node(-1);
        Node* temp = ans;
        while(head!=NULL){
            Node* t = new Node(head->val);
            temp->next = t;
            temp = temp->next;
            mp[head]=t;
            head = head->next;
        }
        Node* track = ans->next;
        while(oldhead!=NULL){
            Node* rand = mp[oldhead->random];
            track->random = rand;
            track = track->next;
            oldhead=oldhead->next;
        }
        return ans->next;
        
    }
};