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
    bool isBalanced(TreeNode* root) {
       
        if(depthBalance(root)==-1) return false;
        return true;
    }
    int depthBalance(TreeNode* root)
    {
         if(!root) return 0;
        int lh = depthBalance(root->left);
        int rh = depthBalance(root->right);
// checks if left and right subtrees are balanced individually
        if(lh==-1 || rh==-1) return -1;
//checks if difference is balanced
        if(abs(lh-rh)>1) return -1;
        return 1 + max(lh,rh);
    }
};