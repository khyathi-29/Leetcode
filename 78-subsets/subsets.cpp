class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        Helper(0,nums,ans,temp);
        return ans;
    }
    void Helper(int index,vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        Helper(index+1,nums,ans,temp);
        temp.push_back(nums[index]);
        Helper(index+1,nums,ans,temp);
        temp.pop_back();
    }
};