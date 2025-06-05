class Solution {
    public int coinChange(int[] coins, int amount) {

        int[] ans = new int[amount+1];
        Arrays.fill(ans,amount+1);
        ans[0]=0;
        for(int i = 1 ; i<=amount ; i++)
        {
            for(int j = 0;j < coins.length; j++ )
            {
                if(i>=coins[j])
                {
                    ans[i] = Math.min(ans[i],ans[i-coins[j]]+1);
                }
            }
        }
        int i;
        i = (ans[amount]<amount+1) ? ans[amount]: -1;
      return i;
    }
}