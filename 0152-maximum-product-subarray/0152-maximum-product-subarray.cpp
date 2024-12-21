class Solution {
public:
   // here we are keeping track of curMax and curMin element
   //
    int maxProduct(vector<int>& nums) {
       int cMax = 1;// current max
       int cMin = 1;// current min
       int ans=nums[0];
       for(int i=0;i<nums.size();i++)
       {
            int temp = cMax*nums[i];//store before update to check for cMin
            cMax=max(max(cMax*nums[i],cMin*nums[i]),nums[i]);
            cMin=min(min(cMin*nums[i],temp),nums[i]);
            ans=max(ans,cMax);
       } 
       return ans;
    }
};