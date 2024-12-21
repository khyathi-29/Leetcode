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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 1;
        queue<pair<TreeNode*, long long int>> q;
        int maxwidth = 0;
        q.push({root,0});
        while(!q.empty())
        {
            int size = q.size();
            long long int start = 0;
            long long int end =0;
            long long int min_i = q.front().second;//min index for each row
            for(int i = 0;i<size;i++)
            {
                TreeNode* temp = q.front().first;
                long long index = q.front().second-min_i; 
                // index after subtraction of 1st min index from index
                q.pop();
                if(i==0) start = index;
                if(i==size-1) end = index;
                if(temp->left) q.push({temp->left,index*2+1});
                if(temp->right) q.push({temp->right,2*index+2});
            }
            maxwidth = max(maxwidth,int(end-start+1));
        }
        return maxwidth;
    }
};