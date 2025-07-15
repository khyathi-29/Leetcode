class Solution {
public:
    double myPow(double x, int n) {
        int pow = 1;
        double ans = 1;
        long nn=n;
        if(n==1) return x;
        if(x==1 || n==0) return 1;
        if(n<0) {
            pow =-1;
            nn=-(long)n;
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
        cout<<pow<<endl;
        if(pow==-1) return 1/ans;
        else return ans;
        
    }
};