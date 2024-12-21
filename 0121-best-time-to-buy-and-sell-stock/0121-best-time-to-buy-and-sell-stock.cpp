class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curmin = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(curmin>prices[i])
            {
                curmin=prices[i];
            }
            profit=max(profit,prices[i]-curmin);
        }
        return profit;
        
    }
};