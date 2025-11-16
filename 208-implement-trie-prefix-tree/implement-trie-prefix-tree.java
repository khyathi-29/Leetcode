class TrieNode {
    public TrieNode[] links;
    boolean isEnd;

    public TrieNode(){
        links = new TrieNode[26];
    }

    public TrieNode getNode( char c){
        return links[c-'a'];
    }
    public void addNode(char c , TrieNode temp){
        links[c-'a'] = temp;
    }
    public boolean isEnd(){
        return isEnd;
    }
    public void setEnd(){
        isEnd = true;
    }
}
class Trie {
    public TrieNode root;
    public Trie() {
        root = new TrieNode();  
    } 
    
    public void insert(String word) {
        TrieNode node = root;
        for( char c : word.toCharArray())
        {
            if( node.getNode(c)==null){
                node.addNode( c, new TrieNode());
            }
            node = node.getNode(c);
        }
        node.setEnd();
        
    }
    
    public boolean search(String word) {
         TrieNode node = root;
        for( char c : word.toCharArray())
        {
            if( node.getNode(c)==null){
                 return false;
            }
            node = node.getNode(c);
        }
         return node.isEnd()==true;
    }
    
    public boolean startsWith(String prefix) {
         TrieNode node = root;
        for( char c : prefix.toCharArray())
        {
            if( node.getNode(c)==null){
                 return false;
            }
            node = node.getNode(c);
        }

        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */