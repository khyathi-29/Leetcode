class Solution {
public:
     // Helper function to check if a target number of alloys is possible with any machine
    bool isValid(int target, int n, int k, int budget,
                 vector<vector<int>>& composition,
                 vector<int>& stock, vector<int>& cost) {
        for (int i = 0; i < k; i++) {
            long long remainingBudget = budget;
            for (int j = 0; j < n && remainingBudget >= 0; j++) {
                long long needed = max(0LL, 1LL * target *composition[i][j] - stock[j]);
                remainingBudget -= needed * cost[j];
            }
            if (remainingBudget >= 0) return true;  // Found a valid machine
        }
        return false;  // No machine can produce target alloys within budget
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        long long left = 0,right = budget + *max_element(stock.begin(), stock.end());
        while (left < right) {
            long long mid = (left + right + 1) >> 1;
            if (isValid(mid, n, k, budget, composition, stock, cost)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return (int)left;
        
    }
};