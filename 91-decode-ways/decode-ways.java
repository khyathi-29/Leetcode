class Solution {
    public int numDecodings(String s) {
        int len = s.length();
        int[] dp = new int[len+1];
        Arrays.fill(dp,0);
         dp[len]=1;
         for(int i=len-1;i>-1;i--){
            if(s.charAt(i)=='0')dp[i]=0;
            else{
                dp[i]=dp[i+1];
                if(i<len-1 && (s.charAt(i)=='1' || (s.charAt(i)=='2' && s.charAt(i+1)<'7')))
                {
                    dp[i]+=dp[i+2];
                }
            }
         }
         return dp[0];
        
    }
}