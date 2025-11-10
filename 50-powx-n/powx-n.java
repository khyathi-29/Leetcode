class Solution {
    public double myPow(double x, int n) {
        double ans = 1;
        long nn = n;
        if(x==1 || n==0) return 1;
        if(n<0) {
            x= 1/x;
            nn = -nn;
        }
        while(nn!=0)
        {
            if(nn%2==0){
                 x = x*x;
                 nn=nn/2;
            }
            else{
                ans = ans*x;
                nn= nn-1;
            } 
        }
        return ans;
    }
}