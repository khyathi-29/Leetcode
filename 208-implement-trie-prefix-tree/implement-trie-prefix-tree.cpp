struct Node {
       Node* list[26];
       bool End = false;
       void assignNode(char c , Node* node)
       {
        list[c-'a']=node;
       }
       Node* returnNode(char c)
       {
         return list[c-'a'];
       }
       bool isEnd(){
         return End;
       }
       void setEnd(){
         End = true;
       }
    };
class Trie {
      Node* root;
public:
        Trie(){
            root = new Node();
        }
        
    
    void insert(string word) {
        Node* temp  = root;
        for( int i = 0;i< word.size() ; i++ )
        {
            if(temp->returnNode(word[i])==NULL)
            {
               temp->assignNode(word[i],new Node());
            }
            temp = temp->returnNode(word[i]);
        }
        temp->setEnd();
        
    }
    
    bool search(string word) {
        Node* temp  = root;
        for( int i = 0;i< word.size() ; i++ )
        {
            if(temp->returnNode(word[i])==NULL)
            {
                return false;
            }
            temp = temp->returnNode(word[i]);
        }
        
        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* temp  = root;
        for( int i = 0;i< prefix.size() ; i++ )
        {
            if(temp->returnNode(prefix[i])==NULL)
            {
                return false;
            }
            temp = temp->returnNode(prefix[i]);
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