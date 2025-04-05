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
        map<int,map<int,multiset<int>>> mp;
        vector<vector<int>> ans;
        Helper(root,0,0,mp);
        for(auto& it : mp){
            vector<int> temp;
            for( auto it2 : it.second){
                for(auto& it3 : it2.second) temp.push_back(it3);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
    void Helper(TreeNode* root, int vertical,int horizontal,map<int,map<int,multiset<int>>>& mp){
        if(root==NULL) return;
        else mp[horizontal][vertical].insert(root->val);
        Helper(root->left,vertical+1,horizontal-1,mp);
        Helper(root->right,vertical+1,horizontal+1,mp);
    }
};