class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> a;
        permutation(0,nums,a);
        return a;
        
    }
    void permutation(int index , vector<int>& nums,vector<vector<int>>& a) {
        if(index==nums.size())
        {
            a.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            int temp = nums[index];
            nums[index]=nums[i];
            nums[i]=temp;
            permutation(index+1,nums,a);
            temp = nums[index];
            nums[index]=nums[i];
            nums[i]=temp;
        }
        
    }
};