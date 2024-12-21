class Listnode{
public:
    int key;
    int val;
    Listnode* next;
    Listnode* prev;

    Listnode(){
        key = -1;
        val = -1;
    }
    Listnode(int k, int v)
    {
        key=k;
        val = v;
    }
};
class LRUCache {
public:
    Listnode* head = new Listnode(-1, -1);
    Listnode* tail = new Listnode(-1, -1);
    int cap;
    unordered_map<int, Listnode* > m;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(Listnode* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void addNodeFront(Listnode* node)
    {
         Listnode* Next = head->next;
         node->next = Next;
         Next->prev = node;
         head->next = node;
         node->prev = head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            Listnode* node = m[key];
            int k = node->val;
            m.erase(key);
            deleteNode(node);
            addNodeFront(new Listnode(key,k));
            m[key]=head->next;
            return k;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            Listnode* node = m[key];
            node->val = value;
            m.erase(key);
            deleteNode(node);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNodeFront(new Listnode(key,value));
        m[key]=head->next;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */