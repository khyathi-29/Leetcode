class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> a;
      for(int i=0;i<nums.size();i++)
      {
        int remaining = target- nums[i];
        if(a.find(remaining)!=a.end())
        {
            return {a[remaining],i};
        }
        a[nums[i]]=i;
      }
      return {-1,-1};}
};