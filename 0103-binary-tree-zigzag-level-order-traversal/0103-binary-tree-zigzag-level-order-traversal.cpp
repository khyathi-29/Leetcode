/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue <TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        q.push(root);
        bool lefttoright = true;
        while(!q.empty())
        {
           int size = q.size();
           vector<int> te;
           for(int i=0;i<size;i++)
           {
            
             TreeNode* temp = q.front();
             q.pop();
             te.push_back(temp->val);
             if(temp->left!=NULL) q.push(temp->left);
             if(temp->right!=NULL) q.push(temp->right);
           }
           if(lefttoright) ans.push_back(te);
           else 
           {
            reverse(te.begin(),te.end());
            ans.push_back(te);
            }
            lefttoright = !lefttoright;
    
    }
    return ans; 
    }
};