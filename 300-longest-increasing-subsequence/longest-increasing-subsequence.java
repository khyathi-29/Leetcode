class Solution {
    public int lengthOfLIS(int[] nums) {
      int s = nums.length; 
      int[] ans = new int[s];
      ans[s-1]= 1;
      int sol = 1;
      for(int i=s-2;i>-1;i--)
      {
        ans[i]=1;
        for(int j = i+1; j<nums.length;j++)
        {
            if(nums[j]>nums[i])
            {
                ans[i]= Math.max(ans[i],ans[j]+1);
                sol = Math.max(sol,ans[i]);
            }
        }
        
      }
      return sol;

    }
}