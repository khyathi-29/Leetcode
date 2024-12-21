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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int,int> iMap;
        for(int i=0;i<inorder.size();i++)
        {
            iMap[inorder[i]]=i;
        }
         TreeNode* root = builder(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,iMap);
         return root;
    }
    TreeNode* builder(vector<int>& inorder, int iS, int iE, vector<int>& postorder, int pS, int pE, map<int,int>& iMap )
    {
        if(iS>iE || pS>pE) return NULL;
        TreeNode* root = new TreeNode(postorder[pE]);
        int rootIndex = iMap[root->val];
        int remaining = rootIndex-iS;
        root->left = builder(inorder,iS,iS + remaining -1,postorder, pS, pS+remaining-1,iMap );
        root->right = builder(inorder, rootIndex + 1, iE, postorder, pS+remaining, pE-1, iMap);
        return root;
    }
};