class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
       vector<int> temp;
       Helper(0,nums,temp,ans);
       return ans;
    }
    void Helper(int index, vector<int>& nums,vector<int>& temp, vector<vector<int>>& ans)
    {
        ans.push_back(temp);
        if(index == nums.size())
        { 
            return;
        }
        for( int i = index ; i < nums.size();i++)
        {
             if(i!=index && nums[i]==nums[i-1]) continue;
             temp.push_back(nums[i]);
             Helper(i+1,nums,temp,ans);
             temp.pop_back();
        }
    }
};

