class Node{
    int key;
    int val;
    Node next,prev;
    Node(int key,int val){
         this.key = key;
         this.val = val;
    }

}
class LRUCache {
    int cap;
    int size;
    Map<Integer,Node> mp;
    Node start, end;
    public LRUCache(int capacity) {
       cap = capacity;
       size = 0;
       mp = new HashMap<>();
       start = new Node(0,0);
       end = new Node(0,0);
       start.next = end;
       end.prev = start;
    }
    
    public int get(int key) {
        if(!mp.containsKey(key)) return -1;
        else{
            Node temp = mp.get(key);
            removeNode(temp);
            addNodeFront(temp);
            return temp.val;
        }
    }
    
    public void put(int key, int value) {
        if(!mp.containsKey(key))
        {
            Node temp = new Node(key,value);
            mp.put(key,temp);
            addNodeFront(temp);
            if(size<cap)
            {
                 size++;
            }
            else{
                Node delete = end.prev;
                mp.remove(delete.key);
                removeNode(delete);
            }
        }
        else{
            Node temp = mp.get(key);
            temp.val = value;
            removeNode(temp);
            addNodeFront(temp);
        }
    }
    
    public void removeNode(Node curr)
    {
        Node n = curr.next;
        Node p = curr.prev;
        p.next = n;
        n.prev = p;
    }
    public void addNodeFront(Node curr)
    {
        Node n = start.next;
        start.next = curr;
        curr.prev = start;
        curr.next = n;
        n.prev = curr;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */