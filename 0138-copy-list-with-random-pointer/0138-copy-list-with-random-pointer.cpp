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
        
        unordered_map<Node*,Node*> a;
        Node* temp =head;
        while(temp!=NULL)
        {
            Node* copy = new Node(temp->val);
            a[temp]=copy;
            temp=temp->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            Node* copy;
            copy = a[temp];
            if(temp->next!=NULL)
            copy->next = a[temp->next];
            if(temp->random!=NULL)
            copy->random = a[temp->random];
            temp=temp->next;
        }
      
        return a[head];
    }
};