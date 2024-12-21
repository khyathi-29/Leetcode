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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bstHelper(preorder,i,INT_MAX);
    }
    TreeNode* bstHelper(vector<int>& A,int& i, int bound){
        if(i==A.size() || A[i]> bound) return NULL;
        TreeNode* temp = new TreeNode(A[i]);
        i+=1;
        temp->left = bstHelper(A,i,temp->val);
        temp->right = bstHelper(A,i,bound);
        return temp;
    }

};