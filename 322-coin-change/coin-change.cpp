class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp ( amount+1,amount+1);
        dp[0]=0;
        for(int i =1 ;i<=amount;i++)
        {
            for(int j =0 ; j< coins.size(); j++)
            {
                if(coins[j]<=i)
                {
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount]!=amount+1) return dp[amount];
        else return -1;
    }
};