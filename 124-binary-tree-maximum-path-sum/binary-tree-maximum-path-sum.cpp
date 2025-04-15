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
    int maxPathSum(TreeNode* root) {
       if(root==NULL) return 0;
       int maxval = root->val;
       maxPathSumHelper(root,maxval); 
       return maxval;
    }
    int maxPathSumHelper(TreeNode* root,int& maxval){
        if(root==NULL) return 0;
        int lsum = max(0,maxPathSumHelper(root->left,maxval));
        int rsum = max(0,maxPathSumHelper(root->right,maxval));
        maxval = max(maxval,lsum+rsum+root->val);
        return root->val + max(lsum,rsum);
    }
};