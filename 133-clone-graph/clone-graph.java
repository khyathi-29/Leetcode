/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        Map<Node, Node> mp = new HashMap<>();
        if(node==null) return node;
        Node ans = new Node(node.val);
        mp.put(node, ans);
        Queue<Node> q = new LinkedList<>();
        q.add(node);
        while(!q.isEmpty()){
           Node old = q.poll();
           Node deep = mp.get(old);
           for( Node i : old.neighbors){
               if(mp.get(i)==null){
                 mp.put(i,new Node(i.val));
                 q.add(i); // new node not yet computed
               }
              deep.neighbors.add(mp.get(i));
           }
        }
        return ans;
        
    }
}