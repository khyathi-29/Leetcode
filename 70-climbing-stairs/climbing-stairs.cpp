class Solution {
public:
    int climbStairs(int n) {
        int n1 = 1;
        int n2= 2;
        int ans;
        if(n<=2) return n;
        for(int i = 3 ;i<=n;i++)
        {
            ans = n1+n2;
            n1 = n2;
            n2 = ans;
        }
       return ans;
    }
};