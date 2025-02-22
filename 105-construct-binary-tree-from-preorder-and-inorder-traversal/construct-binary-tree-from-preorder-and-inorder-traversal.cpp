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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     map<int,int> lrsubtree;// to divide into left and right sub trees
     for(int i=0;i<inorder.size();i++){
        lrsubtree[inorder[i]]=i;
     }
     return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,lrsubtree);
    }
    TreeNode* helper(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is, int ie, map<int,int>& lr){
        if( ps > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int rootindex = lr[root->val];// to divide as left subtree and right subtree;
        int lsize = rootindex-is;
        root->left = helper(preorder,ps+1,ps+lsize,inorder,is,rootindex-1,lr);
        root->right = helper(preorder,ps+lsize+1,pe,inorder,rootindex+1,ie,lr);
        return root;
    } 
};