struct Node{
    Node* links[26];
    bool flag = false;
    void putNode(char ch,Node* node){
        links[ch-'a']= node;
    }
    Node* getNode(char ch){
        return links[ch-'a'];
    }
    void makeEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
private:  Node* root;
public:
    Trie() {
       root = new Node(); 
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->getNode(word[i])){
                node->putNode(word[i],new Node());
            }
            node = node->getNode(word[i]);
        }
        node->makeEnd();
        
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->getNode(word[i])) return false;  
            node = node->getNode(word[i]);
        }
        return node->isEnd(); return false;
        
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->getNode(prefix[i])) return false;  
            node = node->getNode(prefix[i]);
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */