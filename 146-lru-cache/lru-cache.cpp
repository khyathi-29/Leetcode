class Node{
 public:
    int key;
    int value;
    Node* prev = NULL;
    Node* next = NULL;

    Node(int key, int val){
        this->key = key;
        this->value = val;
    }
    int getValue(){
        return value;
    }

};
class LRUCache {
    Node* start;
    Node* end;
    unordered_map<int,Node*> m;
    int capacity;
public:
    LRUCache(int capacity) {
        start = new Node(-1,-1);
        end = new Node(-1,-1);
        start->next = end;
        end->prev = start;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
           Node* temp = m[key];
           deleteNode(key);  
           addNodeAtFront(temp);
           m[key] = temp;
           return temp->value;
        }
        else return -1;
    }
    void addNodeAtFront(Node* temp)
    {
        
        temp->next = start->next;
        start->next->prev = temp;
        start->next = temp;
        temp->prev = start;

    }
    void deleteNode(int key){
        Node* temp = m[key];
        m[key]->prev->next =temp->next;
        m[key]->next->prev = temp->prev;
    }
    void put(int key, int val) {
        if(m.find(key)!=m.end())
        {  
            Node* temp = m[key];
            temp->value = val;
            deleteNode(key);
            addNodeAtFront(temp);
            m[key] = temp;
        }
        else if(capacity > m.size()){
            Node* temp = new Node(key,val);
            addNodeAtFront(temp);
            m[key] = temp;
        }
        else{
            int k = end->prev->key;
            deleteNode(end->prev->key);
            m.erase(k);

            Node* temp = new Node(key,val);
            addNodeAtFront(temp);
            m[key] = temp;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */