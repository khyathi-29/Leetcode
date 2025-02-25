struct Node{
    Node* links[26];
    bool flag = false;
    void setCh(char c, Node* node){
        links[c-'a']= node;
    }
    Node* getCh(char c){
        return links[c-'a'];
    }
    bool getEnd(){
        return flag;
    }
    void setEnd(){
        flag = true;
    }

};
class WordDictionary {
private: Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->getCh(word[i])){
                node->setCh(word[i],new Node());
            }
            node = node->getCh(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        return searchHelper(word,root);
        
    }
    bool searchHelper(string word, Node* node) {
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
              for(char c ='a';c<='z';c++){
                if(node->getCh(c)!=NULL && searchHelper(word.substr(i+1),node->getCh(c))!=false) return true;
              }
              return false;
            }
            if(!node->getCh(word[i])) return false;  
            node = node->getCh(word[i]);
        }
        return node->getEnd();
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */