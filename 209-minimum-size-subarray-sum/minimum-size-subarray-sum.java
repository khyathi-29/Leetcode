class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int ans = nums.length+1;
        int low = 0;
        int sum =0;
        for(int i=0;i<nums.length;i++)
        {
          sum+=nums[i];
          while(sum>=target){
            ans = Math.min(ans,i+1-low);
            sum = sum-nums[low];
            low++;
          }
         
        }
        if(ans==nums.length+1) return 0;
        else return ans;

    }
}