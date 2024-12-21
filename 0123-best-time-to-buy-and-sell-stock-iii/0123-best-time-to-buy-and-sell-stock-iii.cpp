class Solution {
public:
// similar to previous problem but along with that we include k to keep track 
// of number of transactions
//use memoization 
//use tablulation we can also space optimize like previous problem
    int helper(vector<int>& prices,int index,int buy,int k,vector<vector<vector<int>>>& dp)
    {
        if(k==0 || index==prices.size()) return 0;
        int profit=0;
        if(dp[index][k][buy]!=-1) return dp[index][k][buy];
        if(buy!=0)
        {
            profit = max(-prices[index]+helper(prices,index+1,0,k,dp),
                        helper(prices,index+1,1,k,dp));
        }
        else
        {
            profit = max(prices[index]+helper(prices,index+1,1,k-1,dp),
                        helper(prices,index+1,0,k,dp));
        }
        dp[index][k][buy]=profit;
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int k=2;
        int n = prices.size();
        //vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        vector<vector<int>> ahead(k+1,vector<int>(2,0));
        vector<vector<int>> current(k+1,vector<int>(2,0));
        for(int i=n-1;i>-1;i--)
        {
            for(int j=1;j<k+1;j++)
            {
                for(int l=0;l<2;l++)
                {
                    if(l!=0)//buy case
                    {
                        dp[i][j][l]= max(-prices[i]+ dp[i+1][j][0],dp[i+1][j][1]);
                        current[j][l]=max(-prices[i]+ahead[j][0],ahead[j][1]);
                    }
                    else{//sell
                        dp[i][j][l]= max(prices[i]+ dp[i+1][j-1][1],dp[i+1][j][0]);
                        // makesure to decrease the transaction number
                    }
                }
            }
        }
        return dp[0][2][1];//helper(prices,0,1,2,dp);
    }
};