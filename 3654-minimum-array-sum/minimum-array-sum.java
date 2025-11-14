class Solution {
    public int minArraySum(int[] nums, int d, int op1, int op2) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE;
        int[][][] dp = new int[n+1][op1+1][op2+1];
        int inf = 1000000;
        for (int[][] layer : dp) {
            for (int[] row : layer) {
                Arrays.fill(row, inf);
            }
        }
        dp[0][0][0] = 0;
        for(int i = 1;i<=n;i++)
        {
            int currentNum = nums[i - 1];
            for( int j = 0;j<=op1;j++)
            {
                for( int k = 0;k<=op2;k++)
                {
                      dp[i][j][k] = dp[i-1][j][k]+ currentNum;
                      if (j > 0) {
                        int halfValue = (currentNum + 1) / 2;  // Ceiling division
                        dp[i][j][k] = Math.min(dp[i][j][k], 
                                              dp[i - 1][j - 1][k] + halfValue);
                    }
                  
                    // Option 3: Apply operation 2 (subtract d)
                    if (k > 0 && currentNum >= d) {
                        dp[i][j][k] = Math.min(dp[i][j][k], 
                                              dp[i - 1][j][k - 1] + (currentNum - d));
                    }
                  
                    // Option 4: Apply both operations
                    if (j > 0 && k > 0) {
                        // Apply op1 first, then op2
                        int halfValue = (currentNum + 1) / 2;
                        if (halfValue >= d) {
                            dp[i][j][k] = Math.min(dp[i][j][k], 
                                                  dp[i - 1][j - 1][k - 1] + (halfValue - d));
                        }
                      
                        // Apply op2 first, then op1
                        if (currentNum >= d) {
                            int afterSubtract = currentNum - d;
                            int finalValue = (afterSubtract + 1) / 2;
                            dp[i][j][k] = Math.min(dp[i][j][k], 
                                                  dp[i - 1][j - 1][k - 1] + finalValue);
                        }
                    }
                    if(i==n) ans = Math.min(dp[i][j][k],ans);
                }
            }
        }
        return ans;
    }
}