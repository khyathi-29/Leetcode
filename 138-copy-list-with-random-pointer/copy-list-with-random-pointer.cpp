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
        Node* h = head;
        if(h==NULL) return h;
        // making new nodes and placing them next to the old nodes;
        while(h!=NULL){
         Node* temp = new Node(h->val);
         temp->next = h->next;
         h->next = temp;
         h = h->next->next;
        }
        h=head;
        Node* ans = head->next;
        // now mapping random pointers
        while(h!=NULL){
            Node* rand = h->random;
            if(rand)h->next->random = rand->next;// since new pointer would be next to old pointer
            else h->next->random = NULL;
            h=h->next->next; 

        }
        h=head;
        // Now separating new and old pointers
        while(h!=NULL){
            Node* newNode = h->next;
            h->next = newNode->next; // Restore original list's next pointer
            newNode->next = (h->next != NULL) ? h->next->next : NULL; // Set next pointer for copied list
            h = h->next; // Move to the next original node
        }
        return ans;
    }
};