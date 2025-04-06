/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //map node to parents for traversal till target;
        TreeNode* Root = root;
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> mp;
        unordered_set<TreeNode*> visited;
        Parents(root,mp);
        Dfs(target,k,visited,mp,ans);
        return ans;
        
    }
    void Dfs(TreeNode* target,int k,unordered_set<TreeNode*>& visited, unordered_map<TreeNode*,TreeNode*>& mp,vector<int>& ans){
        // if node unvisited
        if(target == NULL) return;
        if(k==0 && visited.find(target)==visited.end()) ans.push_back(target->val);
        if(visited.find(target)!=visited.end()) return; // already visited so return;
        visited.insert(target);
        Dfs(target->left,k-1,visited,mp,ans);
        Dfs(target->right,k-1,visited,mp,ans);
        if(mp.find(target)!=mp.end()) Dfs(mp[target],k-1,visited,mp,ans);
        
    }
    void Parents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mp)
    {
        if(root==NULL) return;
        if(root->left){
            mp[root->left]=root;
            Parents(root->left,mp);
        }
        if(root->right){
            mp[root->right]=root;
            Parents(root->right,mp);
        }
    }

};