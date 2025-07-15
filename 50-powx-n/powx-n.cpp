class Solution {
public:
    double myPow(double x, int n) {
        int pow = 1;
        double ans = 1;
        long nn=n;
        // to avoid integer 
        if(n==1) return x;
        if(x==1 || n==0) return 1;
        if(nn<0)
        {
            x = 1/x;
            nn = -nn;
        }
        while(nn!=0)
        {
          if((nn%2)==0){
             x*=x;
             nn=nn/2;
             }
           else{
            ans = ans*x;
            nn=nn-1;
           } 
        }
        return ans;
    }
};