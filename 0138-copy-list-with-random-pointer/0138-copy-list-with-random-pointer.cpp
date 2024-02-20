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
        
       /* unordered_map<Node*,Node*> a;
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
    }*/
        Node* temp = head;
        if(head==NULL)
        {
            return NULL;
        }
        while(temp!=NULL)
        {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp=temp->next->next;
        }
        
        temp = head;
        while(temp!=NULL)
        {
            
            Node* copy ;
            copy = temp->next;
            if(temp->random!=NULL)
            copy->random = temp->random->next;
            temp=temp->next->next;
        }
        temp = head;
        Node* a = head->next;
        Node* ans = head->next;
        while(temp!=NULL && a!=NULL)
        {
            temp->next = temp->next->next;
            if(a->next!=NULL)
            a->next = a->next->next;
            a=a->next;
            temp = temp->next;
        }
        
        return ans;
    }
        
};