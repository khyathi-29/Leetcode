class Solution {
public:
    void swap(int i, int j, vector<int>& nums)
    {
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
        return;
    }
    void permutehelper(int index, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = index;i<nums.size();i++)
        {
            swap(index,i,nums);
            permutehelper(index+1,nums,ans);
            swap(index,i,nums);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutehelper(0,nums,ans);
        return ans;
    }
};