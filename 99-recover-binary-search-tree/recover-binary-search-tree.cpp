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
     TreeNode* prev = new TreeNode(INT_MIN);
     TreeNode* first;
     TreeNode* middle;
     TreeNode* last;
    void recoverTree(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parent;
        Helper(root);
        if(first && last){
            int t = first->val;
            first->val = last->val;
            last->val = t;
        }
        else{
            int t = first->val;
            first->val = middle->val;
            middle->val = t;
        }
        return;
    }
    void Helper(TreeNode* root){
          if(root==NULL) return;
          Helper(root->left);
          if(first==NULL && prev->val > root->val){
              first = prev;
              middle = root;
          }
          if(first!=NULL && prev->val > root->val){
             last = root;
          }
          prev = root;
          Helper(root->right);
          return;
    }
};