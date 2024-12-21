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
 class BSTIterator {
private:
    stack<TreeNode* > s;
    bool isreverse;
public:
    BSTIterator(TreeNode* root, bool reverse) {
        isreverse = reverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();
        if(isreverse!=true) pushAll(node->left);
        else pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    void pushAll(TreeNode* node)
    {
       while(node)
       {
        s.push(node);
        if(isreverse!=true) node = node->right;
        else node = node->left;
       }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator* l = new BSTIterator(root, true);
        BSTIterator* r = new BSTIterator(root, false);
        int i = l->next();
        int j = r->next();
        while(i<j)
        {
            if(i+j==k) return true;
            if(i+j<k) (i=l->next());
            else j = r->next();
        }
        return false;

    }
};