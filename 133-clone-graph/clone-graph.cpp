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
//using bfs or dfs O(V+E) && 0(V)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* main = new Node(node->val);
        unordered_map<Node*,Node*> update;// linking old node to new
        update[node]=main;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* temp = q.front();
            cout<<temp->val<<endl;
            q.pop();
            for(Node* i : temp->neighbors){
                if(update.find(i)==update.end()){
                    Node* n = new Node(i->val);
                    update[i] =n;
                    q.push(i); //push into queue since its unvisited and found first time
                }
                update[temp]->neighbors.push_back(update[i]);
            }

        }
        return main;
        
    }
};