class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==1) return cost[0];
        if(cost.size()==2) return min(cost[0],cost[1]);
        int prev1 = 0;
        int prev2 = 0;
        int current;
        for(int i=2;i<cost.size()+1;i++)
        {
            current = min(prev1+cost[i-1],prev2+cost[i-2]);
            prev2=prev1;
            prev1=current;
        }
        return current;
    }
};