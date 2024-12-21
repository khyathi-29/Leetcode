class Solution {
public:
    int climbStairs(int n) {
        vector<int>a (n,0);
        if(n==1 || n==2) return n;
        else{
            a[0]=1;
            a[1]=2;
        }
        for(int i=2;i<a.size();i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
      return a[n-1];
        
    }
};