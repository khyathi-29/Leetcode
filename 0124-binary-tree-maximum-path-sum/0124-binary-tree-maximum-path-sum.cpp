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
        int maxSum=root->val;
        Helper(root,maxSum);
        return maxSum;
        
    }
    int Helper(TreeNode* root, int& maxSum)
    {
        if(root==NULL) return 0;
        int lSum = max(0,Helper(root->left,maxSum));//leftTree max path it may not even include a node
        int rSum = max(0,Helper(root->right,maxSum)); // rightTree max path it may not even include a node
        maxSum = max(maxSum,lSum+rSum+root->val);// checking and updating max sum
        return root->val + max(lSum,rSum);  // since we need the branch not the whole path
    }
};