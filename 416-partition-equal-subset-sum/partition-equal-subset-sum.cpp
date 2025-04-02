class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total =0;
        for(int t : nums){
            total+=t;
        }
        if(total%2==1) return false;
        int target = total/2;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(target+1,false));
        for(int i=0;i<=nums.size();i++)//sum =0 base case possible always so
        {
            dp[i][0]=true;
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=target;j++){
                dp[i][j]=dp[i-1][j];//exclude target case;
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[nums.size()][target];
    }
};