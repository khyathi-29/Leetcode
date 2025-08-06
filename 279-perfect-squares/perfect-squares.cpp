class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        int m = sqrt(n);
        for(int i =1 ; i<=m ;i++)
        {
              int sqr = i*i;
            for(int j = sqr ; j<=n; j++)
            {
                dp[j] = min(dp[j],dp[j-sqr]+1);
            }
        }

         return dp[n];
    }
};