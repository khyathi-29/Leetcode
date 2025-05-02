class Node{
    int key;
    int val;
    Node next;
    Node prev;
    public Node(int key,int val){
        this.key = key;
        this.val = val;
    }
}
class LRUCache {
    int capacity;
    Map<Integer, Node> mp;
    Node start;
    Node end;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        start = new Node(-1,-1);
        end = new Node(-1,-1);
        mp = new HashMap<>();
        start.next = end;
        end.prev = start;
    }
    
    public int get(int key) {
        if(mp.containsKey(key)){
           Node temp = mp.get(key);
           removeNode(temp);
           addFront(temp);
           return temp.val;
        }
        else return -1;
    }
    
    public void put(int key, int value) {
        if(mp.containsKey(key)){
            Node temp = mp.get(key);
            removeNode(temp);
        }
        Node ans = new Node(key,value);
        mp.put(key,ans);
        addFront(ans);
        if(mp.size()>capacity){
            //remove lastNode
            //remove lastNode from Hashmap
            Node nodeToDelete = end.prev;
            removeNode(nodeToDelete);
            mp.remove(nodeToDelete.key);
        }
        
    }
    public void addFront(Node node){
        Node n = start.next;
        node.next = n;
        start.next = node;
        n.prev = node;
        node.prev = start;
    }
    public void removeNode(Node node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */