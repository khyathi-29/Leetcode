class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = nums.size()+1;
        int low = 0;
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
          sum+=nums[i];
          while(sum>=target){
            ans = min(ans,i+1-low);
            sum = sum-nums[low];
            low++;
          }
         
        }
        if(ans==nums.size()+1) return 0;
        else return ans;

    }
};