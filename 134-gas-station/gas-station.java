class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0;
        int ans = 0;
        int total2 =0;
        for(int i=0;i<gas.length;i++)
        {
             total += gas[i]-cost[i];
             total2 +=gas[i]-cost[i];
             if(total<0)
             {
                total = 0;
                ans = i+1;
             }
        }
        if(total2<0) return -1;
        else return ans;
    }
}