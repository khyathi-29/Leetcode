class Solution {
public:
    void combinationsumhelper(int index, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int target)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i = index ; i< candidates.size();i++)
        {
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            if(target >= candidates[i]){
                temp.push_back(candidates[i]);
                combinationsumhelper(i+1,candidates,ans,temp,target-candidates[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combinationsumhelper(0,candidates,ans,temp,target);
        return ans;
    }
};