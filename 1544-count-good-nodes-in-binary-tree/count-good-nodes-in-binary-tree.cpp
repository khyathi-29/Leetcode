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
    int goodNodes(TreeNode* root) { 
        int maxi = INT_MIN;
        int count = 0;
        Helper(root,maxi,count);
        return count;
    }
    void Helper(TreeNode* root,int maxi,int& count){
        if(root==NULL) return;
        int k = root->val;
        if(root->val >= maxi){
        cout<<root->val<<endl;
         count+=1;
        }
        maxi = max(maxi,root->val);
        Helper(root->left,maxi,count);
        Helper(root->right,maxi,count);

    }
};