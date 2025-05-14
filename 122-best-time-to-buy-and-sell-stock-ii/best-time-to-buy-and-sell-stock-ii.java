class Solution {
    public int maxProfit(int[] price) {
        int n = price.length;
       int[][] dp = new int[price.length+1][2];
       dp[n][0]=0;
       dp[n][1]=0;
       for(int i=n-1;i>-1;i--){
        for(int j=1;j>-1;j--){
            if(j==1)//buy case
            {
                dp[i][j]=Math.max(dp[i+1][1],-price[i]+dp[i+1][0]);
            }
            else{
                dp[i][j]=Math.max(dp[i+1][0],price[i]+dp[i+1][1]);
            }
        }
       }
       return dp[0][1];
       
    }
}