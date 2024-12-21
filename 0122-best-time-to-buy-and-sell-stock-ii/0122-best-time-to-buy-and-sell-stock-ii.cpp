class Solution {
    // 1. first came up with a recursive solution if we have a option to buy at an
    // index i) we either buy and try to sell it from index+1 or we dont buy at 
    // that particular index  based on profit same case for sell
    //2. First we wrote that recursively
    //3. then we memoized that sp that exponential timecomplexity doesn't come 
    //4. We performed tabularization to reduce the extra space complexity due to 
    //recursive call
    //5. We can further optimize it as ahead and current as given below
public:
    int profit(vector<int>& prices,int buy,int index,vector<vector<int>>& dp)
    {
        int profitans=0;
        if(index==prices.size()) return 0;
        if(dp[buy][index]!=-1) return dp[buy][index];
        if(buy!=0)
        {
           profitans = max(-prices[index]+ profit(prices,0,index+1,dp),profit(prices,1,index+1,dp));
        }
        else
        {
            profitans = max(prices[index]+profit(prices,1,index+1,dp),profit(prices,0,index+1,dp));
        }
        dp[buy][index]=profitans;
        return profitans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //vector<vector<int>> dp(2,vector<int>(n,-1));
        //return profit(prices,1,0,dp);
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> ahead(2,0);
        vector<int> current(2);
        for(int i=n-1;i>-1;i--)
        {
            for(int j=0;j<2;j++)
            {
                //buy case
                if(j==1) {
                    dp[i][j]= max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                    current[j]= max(-prices[i]+ahead[0],ahead[1]);
                }
                //sell case
                else {
                    dp[i][j]= max(prices[i]+dp[i+1][1],dp[i+1][0]);
                    current[j]=max(prices[i]+ahead[1],ahead[0]);
                }
            }
            ahead=current;
        }
        return current[1];//dp[0][1];
    }
};