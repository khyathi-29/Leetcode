class Solution {
public:
    void combinationsum(int index, vector<int>& candidates, vector<int>& temp,vector<vector<int>>& ans, int target)
    {
        if(index==candidates.size()) 
        { 
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
    
            if(target >= candidates[index])
            { 
                temp.push_back(candidates[index]);
                combinationsum(index,candidates,temp,ans,target-candidates[index]);
                temp.pop_back();
            }
            combinationsum(index+1,candidates, temp,ans,target);

        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
       combinationsum(0,candidates,temp,ans,target);
       return ans;
    }
};