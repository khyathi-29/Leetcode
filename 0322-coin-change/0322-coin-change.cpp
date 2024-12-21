//1. we are individually calculating number of coins needed to get amount from 1-amount
// using dp[i] gives min number of coins used to get amount i using it we compute 
//dp[amount] and return it
//2. Here if dp[amount] is not upadated we return -1;
//3.Here we made amount as amt+1 because min coins needed would always < amount+1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);// since to get sum number of coins 
        //would not be greater amount itself.
        dp[0]=0;
        for(int i=1 ; i<amount+1 ;i++)
        {
            for(int j=0 ; j< coins.size();j++)
            {
                if(i>=coins[j])
                {
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        int ans = (dp[amount]<amount+1)? dp[amount]:-1;
        return ans;
        
    }
};