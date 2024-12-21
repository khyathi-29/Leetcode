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
        if(preorder.size()!=inorder.size()) return NULL;
        map<int,int> iMap;
        for(int i=0;i < inorder.size();i++)
        {
            iMap[inorder[i]]=i;
        }
        return Helper(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,iMap);
    }
    TreeNode* Helper(vector<int>& inorder,int iStart, int iEnd, vector<int>& preorder, int pStart, int pEnd,map<int,int> &iMap)
    {

        if(iStart>iEnd || pStart>pEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[pStart]);
        int rootIndex = iMap[root->val];
        int remaining = rootIndex-iStart;
        root->left = Helper(inorder,iStart,rootIndex-1,preorder,pStart+1,pStart+remaining,iMap);
        root->right = Helper(inorder,rootIndex+1,iEnd,preorder,pStart+remaining+1,pEnd,iMap);
        return root;
    }
};