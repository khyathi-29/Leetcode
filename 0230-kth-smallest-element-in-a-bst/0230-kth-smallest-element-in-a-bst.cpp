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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        return Helper(root, k, count);
    }
    int Helper(TreeNode* root, int& k,int& count)
    {
        if(root==NULL || k<count) return -1;
        int left = Helper(root->left, k, count);
        if (left != -1) return left;
        count++;
        if(k==count) return root->val;

        int right = Helper(root->right, k, count);
        if (right != -1) return right;
        return -1;
    }
};