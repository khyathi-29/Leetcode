class Solution {
public:
    double myPow(double x, int n) {
        int k = 1;
        long long kk = n;
        double ans = 1;
        if(n==0) return 1;
        if(x==1) return x;
        if(n<0) {
            kk=long(n);
            kk=-kk;
            k=-1;}
        while(kk>0){
           if((kk%2)==0){
             x*=x;
             kk=kk/2;
             }
           else{
            ans = ans*x;
            kk=kk-1;
           } 
        }
        if(k==-1) return 1/ans;
        else return ans;
    }
};