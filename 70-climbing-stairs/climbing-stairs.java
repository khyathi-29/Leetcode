class Solution {
    public int climbStairs(int n) {
        if(n<3) return n;
        int n1 = 1;
        int n2 = 2;
        int ans = 0;
        for(int i=3;i<=n;i++)
        {
             ans = n1+n2;
             n1 = n2;
             n2 = ans;
        }
        return ans;
    }
}