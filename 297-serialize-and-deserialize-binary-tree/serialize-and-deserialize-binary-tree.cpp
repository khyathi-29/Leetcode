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
        queue<TreeNode*> q;
        if(root==NULL) return "N,";
        string s ="";
        q.push(root);
        while(!q.empty()){
            TreeNode* temp =q.front();
            q.pop();
            if(!temp) s = s+"N,";
            else{
                s = s+ to_string(temp->val)+",";
                q.push(temp->left);
                q.push(temp->right);
            }

        }
        s.pop_back();
        cout<<s<<endl;
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        TreeNode* root=NULL;
        queue<TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s,str,',');
        if(str=="N") return root;
        else{
            root = new TreeNode(stoi(str));
             q.push(root);
        }
        while(getline(s,str,',')){
            TreeNode* temp = q.front();
            q.pop();
            if(str!="N"){
                 temp->left = new TreeNode(stoi(str));
                 q.push(temp->left);
            }
            getline(s,str,',');
            if(str!="N"){
                 temp->right = new TreeNode(stoi(str));
                 q.push(temp->right);
            }

        }
       return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));