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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     queue<pair<TreeNode*, pair<int,int>>> q;
     map<int,map<int,multiset<int>>> m;
     vector<vector<int>> ans;
     if(root==NULL) return ans;
     q.push({root,{0,0}});
     while(!q.empty())
     {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
        TreeNode* node = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        m[col][row].insert(node->val);
        q.pop();
        if(node->left!=NULL) q.push({node->left,{row+1,col-1}});
        if(node->right!=NULL) q.push({node->right,{row+1,col+1}});
        }
     }
     for(auto temp : m )
     {
        vector<int> column;
        for( auto colval: temp.second)
        {
            column.insert(column.end(),colval.second.begin(),colval.second.end());
        }
        ans.push_back(column);
     }
     return ans;
}};