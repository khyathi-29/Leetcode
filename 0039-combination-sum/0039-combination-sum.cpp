class Solution {
public:
    void combination(int index,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>& temp)
    {
        if(index==candidates.size())
        {
            if(target==0)
            ans.push_back(temp);
            return;
        }
        if(target>= candidates[index])
        {
            temp.push_back(candidates[index]);
            combination(index,candidates,target-candidates[index],ans,temp);
            temp.pop_back();
        }
        combination(index+1,candidates,target,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> t;
        vector<vector<int>> ans;
        combination(0,candidates,target,ans,t);
        return ans;
    }
};