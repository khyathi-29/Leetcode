class Solution {
    public int coinChange(int[] coins, int Amount) {
        int[] amount = new int[Amount+1];
        Arrays.fill(amount,Amount+1);
        amount[0]=0;
        for(int i = 1;i < Amount+1;i++)
        {
           for(int j = 0;j<coins.length;j++)
           {
            if(i>=coins[j])
            {
                amount[i] = Math.min(amount[i],amount[i-coins[j]]+1);
            }
           }
        }
        return (amount[Amount]==Amount+1)? -1:amount[Amount];
    }
}