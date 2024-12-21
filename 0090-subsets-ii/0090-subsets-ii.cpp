class Solution {
public:
   void subsetwithdup(vector<int>& nums, vector<vector<int>>& ans, vector<int> &temp,int index)
   {
    ans.push_back(temp);
    if(index==nums.size()) return;
    for(int i = index;i<nums.size();i++)
    {
        if(i!=index && nums[i]==nums[i-1]) continue;
        temp.push_back(nums[i]);
        subsetwithdup(nums,ans,temp,i+1);
        temp.pop_back();
    }
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        subsetwithdup(nums,ans,temp,0);
        return ans;
        
    }
};