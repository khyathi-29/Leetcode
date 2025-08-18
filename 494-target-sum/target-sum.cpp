class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i : nums) total+=i;
        int n = nums.size();
        //Here we take offset as total because all numbers are positive and its bot possible to have negative as index in vector
        vector<vector<int>> dp(n+1,vector<int>(2*total+1,0));
        if(total+target>=dp[0].size()) return 0;
        // considering no elements with sum as zero
        dp[0][total] = 1; 
        for(int i = 1;i<nums.size()+1;i++)
        {
            for(int t = -total; t<total+1;t++)
            {
                if(dp[i-1][t+total]>0)// t-total sum exists in the array
                {
                  dp[i][t+total+nums[i-1]] += dp[i-1][t+total];
                  dp[i][t+total-nums[i-1]] += dp[i-1][t+total];
                }
            }
        }
        return  dp[n][total + target];
    }
};