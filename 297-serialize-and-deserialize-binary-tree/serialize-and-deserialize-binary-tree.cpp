/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root==NULL) return "N,";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL) s +="N,";
            else{
                s = s+to_string(temp->val)+",";
                q.push(temp->left);
                q.push(temp->right);
            }

        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="N,") return NULL;
        stringstream ss(data);
        string temp;
        getline(ss,temp,',');
        TreeNode* root = new TreeNode(stoi(temp));
        queue<TreeNode*> q;
        q.push(root);
        while(getline(ss,temp,','))
        {
            TreeNode* node = q.front();
            q.pop();
            if(temp!="N")
            {
                 node->left = new TreeNode(stoi(temp));
                 q.push(node->left);
            }
            getline(ss,temp,',');
            if(temp!="N"){
                node->right = new TreeNode(stoi(temp));
                 q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));