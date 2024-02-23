class Solution {
public:
    void combination(int index,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>& temp)
    {
        
           if(target==0)
            {
            ans.push_back(temp);
            return;
            }
        
         for(int i = index;i<candidates.size();i++)
         {
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target)
            {
                break;
            }
            
            temp.push_back(candidates[i]);
            combination(i+1,candidates,target-candidates[i],ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> t;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        combination(0,candidates,target,ans,t);
        return ans;
    }
};