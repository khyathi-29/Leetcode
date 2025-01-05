class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> ans(nums.size());
      ans[0]=1;
      int prefixp=1;
      int suffixp=1;
      for(int i=1;i<nums.size();i++)
      {
       prefixp *= nums[i-1];
        ans[i]= prefixp;
      }
      for(int i=nums.size()-2;i>-1;i--)
      {
       suffixp *= nums[i+1];
        ans[i]= ans[i]*suffixp;
      }
      return ans;
    }
};