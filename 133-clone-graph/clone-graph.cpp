/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
     queue<Node*> q;
     unordered_map<Node*,Node*> mp;
     if(node== NULL) return NULL;
     Node* start =  new Node(node->val);
     mp[node]=start;
     q.push(node);
     while(!q.empty()){
        Node* current = q.front();
        q.pop();
        for( auto it : current->neighbors){
            if(mp.find(it)==mp.end()){
                Node* temp = new Node(it->val);
                mp[it]=temp;
                q.push(it);
                // instead of bool we can track elements visited or not visited from map[node] existence
            }
            mp[current]->neighbors.push_back(mp[it]);
    
            }
            
        }
      
     return start; 
    }
};