class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            total_sum += nums[i];
        }
        int target = total_sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        if(total_sum%2==1) return false;
        if(partitionHelper(0,nums,0,total_sum/2,dp)==true) return true;
        return false;

    }
    bool partitionHelper(int sum,vector<int>& nums, int i,int total,vector<vector<int>>& dp){
        if(sum==total) return true;
        if(i>= nums.size() || sum>total) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(partitionHelper(sum+nums[i],nums,i+1,total,dp)) return dp[i][sum]=true;
        if(partitionHelper(sum,nums,i+1,total,dp)) return dp[i][sum]=true;
        return dp[i][sum]=false;
    }
};