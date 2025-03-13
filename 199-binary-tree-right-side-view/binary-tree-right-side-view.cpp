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
    void Helper(TreeNode* root, int level, vector<int>& ans){
        if(ans.size()== level) ans.push_back(root->val);
        if(root->right) Helper(root->right,level+1,ans);
        if(root->left) Helper(root->left,level+1,ans);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root) Helper(root,0,ans);
        return ans;
    }
};