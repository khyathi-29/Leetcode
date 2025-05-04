class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        //vector<vector<int>> dp(2,vector<int>(n,-1));
        //return profit(prices,1,0,dp);
        int[][] dp = new int[n+1][2];
        int[] ahead = new int[2];
        int[] current = new int[2];
        for(int i=n-1;i>-1;i--)
        {
            for(int j=0;j<2;j++)
            {
                //buy case
                if(j==1) {
                    dp[i][j]= Math.max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                    current[j]= Math.max(-prices[i]+ahead[0],ahead[1]);
                }
                //sell case
                else {
                    dp[i][j]= Math.max(prices[i]+dp[i+1][1],dp[i+1][0]);
                    current[j]=Math.max(prices[i]+ahead[1],ahead[0]);
                }
            }
            ahead=current;
        }
        return current[1];//dp[0][1];
    }
    int profit(int[] prices,int buy,int index,int[][] dp)
    {
        int profitans=0;
        if(index==prices.length) return 0;
        if(dp[buy][index]!=-1) return dp[buy][index];
        if(buy!=0)
        {
           profitans = Math.max(-prices[index]+ profit(prices,0,index+1,dp),profit(prices,1,index+1,dp));
        }
        else
        {
            profitans = Math.max(prices[index]+profit(prices,1,index+1,dp),profit(prices,0,index+1,dp));
        }
        dp[buy][index]=profitans;
        return profitans;
    }
    
}