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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        Helper(root,low,high,ans);
        return ans; 
    }
    void Helper(TreeNode* root, int low, int high, int& ans){
        if(root == NULL) return;
        if(root->val >=low && root->val<=high) ans+=root->val;
        Helper(root->left,low,high,ans);
        Helper(root->right,low,high,ans);

    }
};