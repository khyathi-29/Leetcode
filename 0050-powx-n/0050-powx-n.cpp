class Solution {
public:
    double myPow(double x, int n) {

        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return x;
        }
        if(n==-1)
        {
            return 1/x;
        }
         double k;
        if(n%2==0)
        {
            cout<<n%2<<endl;
            k = myPow(x,n/2);
            k = k*k;
            return k;
        }
        else
        {
            k = myPow(x,n/2);
            k=k*k;
            if(n>0)
            {
            return k*x;
            }
            else
            {
                return k/x;
            }
        }
    }
};