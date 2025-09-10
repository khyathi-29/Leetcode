class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int total = 0;
        for( int i : nums) total+=i;
        int n = nums.length;
        int[][] dp = new int[n+1][2*total+1];
        dp[0][total]=1;
        if(target+total>=2*total+1 || target+total<0) return 0;
        for( int i = 1 ;i<=n;i++)
        {
            for(int j = -total ;j<=total;j++)
            {
                if(dp[i-1][j+total]!=0){
                dp[i][j+total+nums[i-1]]+= dp[i-1][j+total];
                dp[i][j+total-nums[i-1]]+=dp[i-1][j+total];
                }
            }
        }
        return dp[n][target+total];
    }
}